#pragma once

#include <string>
using namespace std;

class MotionSensor {
    bool m_motionDetected = false;
    int  m_sensitivity    = 5;   // 1-10
public:
    MotionSensor() = default;
    virtual ~MotionSensor() = default;

    bool detectMotion();
    void setSensitivity(int level);
    int  getSensitivity() const;
};
