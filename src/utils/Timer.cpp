#include "../../include/utils/Timer.h"
#include <iomanip>
#include <sstream>

namespace SmartHome {
namespace Utils {

Timer::Timer() {
    reset();
}

void Timer::start() {
    m_startTime = Clock::now();
    m_running   = true;
}

void Timer::stop() {
    if (m_running) {
        m_endTime = Clock::now();
        m_running = false;
    }
}

void Timer::reset() {
    m_startTime = Clock::now();
    m_endTime   = m_startTime;
    m_running   = false;
}

double Timer::elapsedMilliseconds() const {
    auto end = m_running ? Clock::now() : m_endTime;
    return std::chrono::duration<double, std::milli>(end - m_startTime).count();
}

double Timer::elapsedSeconds() const {
    return elapsedMilliseconds() / 1000.0;
}

bool Timer::isRunning() const { return m_running; }

std::string Timer::formatElapsed() const {
    double ms = elapsedMilliseconds();
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(3) << ms << " ms";
    return oss.str();
}

} // namespace Utils
} // namespace SmartHome
