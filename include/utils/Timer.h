#pragma once

#include <chrono>
#include <string>

namespace SmartHome {
namespace Utils {

/**
 * @brief Simple high-resolution timer for profiling and
 *        scheduling delay measurements.
 */
class Timer {
public:
    Timer();

    void        start();
    void        stop();
    void        reset();

    double      elapsedMilliseconds() const;
    double      elapsedSeconds()      const;
    bool        isRunning()           const;

    std::string formatElapsed()       const;

private:
    using Clock    = std::chrono::high_resolution_clock;
    using TimePoint = Clock::time_point;

    TimePoint m_startTime;
    TimePoint m_endTime;
    bool      m_running{false};
};

} // namespace Utils
} // namespace SmartHome
