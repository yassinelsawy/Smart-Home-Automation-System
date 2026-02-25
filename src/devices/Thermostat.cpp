#include "../../include/devices/Thermostat.h"
#include "../../include/state/InactiveState.h"
#include "../../include/utils/Logger.h"
#include <iostream>

namespace SmartHome {
namespace Devices {

Thermostat::Thermostat(const std::string& name,
                       const std::string& deviceId,
                       const std::string& location)
    : SmartDevice(name, deviceId, location)
    , m_state(std::make_unique<State::InactiveState>())
{}

// ── SmartDevice overrides ─────────────────────────────────────────────────

void Thermostat::turnOn() {
    SmartDevice::turnOn();
    m_state->handleTurnOn();
}

void Thermostat::turnOff() {
    SmartDevice::turnOff();
    m_state->handleTurnOff();
}

void Thermostat::getStatus() const {
    std::cout << "  [Thermostat] " << m_name
              << " | State: "   << m_state->getStateName()
              << " | Target: "  << m_targetTemp  << " °C"
              << " | Current: " << m_currentTemp << " °C"
              << " | Location: "<< m_location << "\n";
}

// ── Thermostat-specific ───────────────────────────────────────────────────

void Thermostat::setTargetTemperature(double celsius) {
    m_targetTemp = celsius;
    Utils::Logger::instance().info(
        m_name + " target temperature set to " + std::to_string(celsius) + " °C",
        "Thermostat");
}

double Thermostat::getTargetTemperature()  const { return m_targetTemp;  }
double Thermostat::getCurrentTemperature() const { return m_currentTemp; }

void Thermostat::setCurrentTemperature(double celsius) {
    m_currentTemp = celsius;
}

// ── State Pattern ─────────────────────────────────────────────────────────

void Thermostat::changeState(std::unique_ptr<State::IDeviceState> newState) {
    if (m_state) m_state->onExit();
    m_state = std::move(newState);
    if (m_state) m_state->onEnter();
}

} // namespace Devices
} // namespace SmartHome
