#include "../../include/devices/Camera.h"
#include "../../include/state/InactiveState.h"
#include "../../include/utils/Logger.h"
#include <algorithm>
#include <iostream>

namespace SmartHome {
namespace Devices {

Camera::Camera(const std::string& name,
               const std::string& deviceId,
               const std::string& location)
    : SmartDevice(name, deviceId, location)
    , m_state(std::make_unique<State::InactiveState>())
{}

// ── SmartDevice overrides ─────────────────────────────────────────────────

void Camera::turnOn() {
    SmartDevice::turnOn();
    m_state->handleTurnOn();
}

void Camera::turnOff() {
    stopRecording();
    SmartDevice::turnOff();
    m_state->handleTurnOff();
}

void Camera::getStatus() const {
    std::cout << "  [Camera] " << m_name
              << " | State: "      << m_state->getStateName()
              << " | Recording: "  << (m_recording ? "YES" : "NO")
              << " | Location: "   << m_location << "\n";
}

// ── Camera-specific ───────────────────────────────────────────────────────

void Camera::startRecording() {
    if (!m_enabled) return;
    m_recording = true;
    notify("RECORDING_STARTED");
    Utils::Logger::instance().info(m_name + " started recording", "Camera");
}

void Camera::stopRecording() {
    m_recording = false;
    Utils::Logger::instance().info(m_name + " stopped recording", "Camera");
}

bool Camera::isRecording() const { return m_recording; }

void Camera::detectMotion() {
    if (!m_enabled) return;
    Utils::Logger::instance().warning(
        m_name + " detected motion!", "Camera");
    notify("MOTION_DETECTED");
}

// ── ISubject ──────────────────────────────────────────────────────────────

void Camera::attach(std::shared_ptr<Observer::IObserver> observer) {
    m_observers.push_back(observer);
}

void Camera::detach(std::shared_ptr<Observer::IObserver> observer) {
    m_observers.erase(
        std::remove(m_observers.begin(), m_observers.end(), observer),
        m_observers.end());
}

void Camera::notify(const std::string& event) {
    for (auto& obs : m_observers) {
        obs->onEvent(m_name, event);
    }
}

// ── State Pattern ─────────────────────────────────────────────────────────

void Camera::changeState(std::unique_ptr<State::IDeviceState> newState) {
    if (m_state) m_state->onExit();
    m_state = std::move(newState);
    if (m_state) m_state->onEnter();
}

} // namespace Devices
} // namespace SmartHome
