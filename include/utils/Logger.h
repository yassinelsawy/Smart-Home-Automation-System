#pragma once

#include <string>
#include <fstream>
#include <mutex>

namespace SmartHome {
namespace Utils {

enum class LogLevel { DEBUG, INFO, WARNING, ERROR };

/**
 * @brief Thread-safe singleton logger.
 *
 * Writes timestamped log entries to both stdout and an
 * optional log file.
 */
class Logger {
public:
    static Logger& instance();

    Logger(const Logger&)            = delete;
    Logger& operator=(const Logger&) = delete;

    void setLogFile(const std::string& filePath);
    void setMinLevel(LogLevel level);

    void debug(const std::string& message,   const std::string& tag = "");
    void info(const std::string& message,    const std::string& tag = "");
    void warning(const std::string& message, const std::string& tag = "");
    void error(const std::string& message,   const std::string& tag = "");

private:
    Logger() = default;
    ~Logger();

    void log(LogLevel level, const std::string& message, const std::string& tag);
    std::string levelToString(LogLevel level) const;
    std::string currentTimestamp()            const;

    LogLevel    m_minLevel{LogLevel::DEBUG};
    std::ofstream m_fileStream;
    std::mutex  m_mutex;
};

} // namespace Utils
} // namespace SmartHome
