#include "../../include/devices/DoorLock.h"
#include "../../include/state/InactiveState.h"
#include "../../include/utils/Logger.h"
#include <algorithm>
#include <iostream>

namespace SmartHome {
namespace Devices {

DoorLock::DoorLock(const std::string& name,
                   const std::string& deviceId,
                   const std::string& location)
    : SmartDevice(name, deviceId, location)
    , m_state(std::make_unique<State::InactiveState>())
{}

// ── SmartDevice overrides ─────────────────────────────────────────────────

void DoorLock::turnOn() {
    SmartDevice::turnOn();
    m_state->handleTurnOn();
}

void DoorLock::turnOff() {
    SmartDevice::turnOff();
    m_state->handleTurnOff();
}

void DoorLock::getStatus() const {
    std::cout << "  [DoorLock] " << m_name
              << " | State: "    << m_state->getStateName()
              << " | Locked: "   << (m_locked ? "YES" : "NO")
              << " | Location: " << m_location << "\n";
}

// ── DoorLock-specific ────────────────────────────────────────────────────

void DoorLock::lock() {
    m_locked = true;
    notify("DOOR_LOCKED");
    Utils::Logger::instance().info(m_name + " locked", "DoorLock");
}

void DoorLock::unlock(const std::string& pinCode) {
    if (pinCode == m_pin) {
        m_locked = false;
        notify("DOOR_UNLOCKED");
        Utils::Logger::instance().info(m_name + " unlocked", "DoorLock");
    } else {
        triggerAlarm();
    }
}

void DoorLock::triggerAlarm() {
    notify("DOOR_TAMPER_ALARM");
    Utils::Logger::instance().error(
        m_name + " TAMPER ALARM – wrong PIN!", "DoorLock");
}

bool DoorLock::isLocked() const { return m_locked; }

void DoorLock::setPin(const std::string& pin) { m_pin = pin; }

// ── ISubject ──────────────────────────────────────────────────────────────

void DoorLock::attach(std::shared_ptr<Observer::IObserver> observer) {
    m_observers.push_back(observer);
}

void DoorLock::detach(std::shared_ptr<Observer::IObserver> observer) {
    m_observers.erase(
        std::remove(m_observers.begin(), m_observers.end(), observer),
        m_observers.end());
}

void DoorLock::notify(const std::string& event) {
    for (auto& obs : m_observers) {
        obs->onEvent(m_name, event);
    }
}

// ── State Pattern ─────────────────────────────────────────────────────────

void DoorLock::changeState(std::unique_ptr<State::IDeviceState> newState) {
    if (m_state) m_state->onExit();
    m_state = std::move(newState);
    if (m_state) m_state->onEnter();
}

} // namespace Devices
} // namespace SmartHome
