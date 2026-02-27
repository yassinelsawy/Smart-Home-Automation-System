#include "../../include/devices/MotionSensor.h"
#include <algorithm>
#include <iostream>
using namespace std;

bool MotionSensor::detectMotion() {
    m_motionDetected = true;
    cout << "[MotionSensor] Motion detected!\n";
    return m_motionDetected;
}

void MotionSensor::setSensitivity(int level) {
    m_sensitivity = max(1, min(10, level));
}

int MotionSensor::getSensitivity() const {
    return m_sensitivity;
}
