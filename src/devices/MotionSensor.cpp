#include "../../include/devices/MotionSensor.h"
#include "../../include/utils/Logger.h"
#include <algorithm>
#include <iostream>

namespace SmartHome {
namespace Devices {

MotionSensor::MotionSensor(const std::string& name,
                           const std::string& deviceId,
                           const std::string& location)
    : SmartDevice(name, deviceId, location)
{}

// ── SmartDevice overrides ─────────────────────────────────────────────────

void MotionSensor::turnOn() {
    SmartDevice::turnOn();
}

void MotionSensor::turnOff() {
    m_motionDetected = false;
    SmartDevice::turnOff();
}

void MotionSensor::getStatus() const {
    std::cout << "  [MotionSensor] " << m_name
              << " | Motion: "      << (m_motionDetected ? "YES" : "NO")
              << " | Sensitivity: " << m_sensitivity
              << " | Location: "    << m_location << "\n";
}

// ── Sensor-specific ───────────────────────────────────────────────────────

void MotionSensor::triggerMotion() {
    if (!m_enabled) return;
    m_motionDetected = true;
    Utils::Logger::instance().warning(
        m_name + " triggered motion alert!", "MotionSensor");
    notify("MOTION_DETECTED");
}

bool MotionSensor::isMotionDetected() const { return m_motionDetected; }

void MotionSensor::setSensitivity(int level) {
    m_sensitivity = std::clamp(level, 1, 10);
}

int MotionSensor::getSensitivity() const { return m_sensitivity; }

// ── ISubject ──────────────────────────────────────────────────────────────

void MotionSensor::attach(std::shared_ptr<Observer::IObserver> observer) {
    m_observers.push_back(observer);
}

void MotionSensor::detach(std::shared_ptr<Observer::IObserver> observer) {
    m_observers.erase(
        std::remove(m_observers.begin(), m_observers.end(), observer),
        m_observers.end());
}

void MotionSensor::notify(const std::string& event) {
    for (auto& obs : m_observers) {
        obs->onEvent(m_name, event);
    }
}

} // namespace Devices
} // namespace SmartHome
