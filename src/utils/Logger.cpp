#include "../../include/utils/Logger.h"
#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>

namespace SmartHome {
namespace Utils {

Logger& Logger::instance() {
    static Logger s_instance;
    return s_instance;
}

Logger::~Logger() {
    if (m_fileStream.is_open()) {
        m_fileStream.close();
    }
}

void Logger::setLogFile(const std::string& filePath) {
    std::lock_guard<std::mutex> lock(m_mutex);
    if (m_fileStream.is_open()) m_fileStream.close();
    m_fileStream.open(filePath, std::ios::app);
}

void Logger::setMinLevel(LogLevel level) {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_minLevel = level;
}

void Logger::debug(const std::string& msg, const std::string& tag) {
    log(LogLevel::DEBUG, msg, tag);
}
void Logger::info(const std::string& msg, const std::string& tag) {
    log(LogLevel::INFO, msg, tag);
}
void Logger::warning(const std::string& msg, const std::string& tag) {
    log(LogLevel::WARNING, msg, tag);
}
void Logger::error(const std::string& msg, const std::string& tag) {
    log(LogLevel::ERROR, msg, tag);
}

void Logger::log(LogLevel level,
                  const std::string& message,
                  const std::string& tag) {
    if (level < m_minLevel) return;
    std::lock_guard<std::mutex> lock(m_mutex);

    std::string entry = "[" + currentTimestamp() + "]"
                      + "[" + levelToString(level) + "]";
    if (!tag.empty()) entry += "[" + tag + "]";
    entry += " " + message;

    std::cout << entry << "\n";
    if (m_fileStream.is_open()) m_fileStream << entry << "\n";
}

std::string Logger::levelToString(LogLevel level) const {
    switch (level) {
        case LogLevel::DEBUG:   return "DEBUG";
        case LogLevel::INFO:    return "INFO ";
        case LogLevel::WARNING: return "WARN ";
        case LogLevel::ERROR:   return "ERROR";
    }
    return "?????";
}

std::string Logger::currentTimestamp() const {
    auto now = std::chrono::system_clock::now();
    auto t   = std::chrono::system_clock::to_time_t(now);
    std::tm tm{};
#ifdef _WIN32
    localtime_s(&tm, &t);
#else
    localtime_r(&t, &tm);
#endif
    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

} // namespace Utils
} // namespace SmartHome
