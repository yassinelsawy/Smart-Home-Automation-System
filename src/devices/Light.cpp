#include "../../include/devices/Light.h"
#include "../../include/state/InactiveState.h"
#include "../../include/utils/Logger.h"
#include <algorithm>
#include <iostream>

namespace SmartHome {
namespace Devices {

Light::Light(const std::string& name,
             const std::string& deviceId,
             const std::string& location)
    : SmartDevice(name, deviceId, location)
    , m_state(std::make_unique<State::InactiveState>())
{}

// ── SmartDevice overrides ─────────────────────────────────────────────────

void Light::turnOn() {
    SmartDevice::turnOn();
    m_state->handleTurnOn();
}

void Light::turnOff() {
    SmartDevice::turnOff();
    m_state->handleTurnOff();
}

void Light::getStatus() const {
    std::cout << "  [Light] " << m_name
              << " | State: "      << m_state->getStateName()
              << " | Brightness: " << m_brightness << "%"
              << " | Color: "      << m_color
              << " | Location: "   << m_location << "\n";
}

// ── Light-specific ────────────────────────────────────────────────────────

void Light::setBrightness(int percent) {
    m_brightness = std::clamp(percent, 0, 100);
    Utils::Logger::instance().debug(
        m_name + " brightness set to " + std::to_string(m_brightness) + "%",
        "Light");
}

int Light::getBrightness() const { return m_brightness; }

void Light::setColor(const std::string& colorHex) {
    m_color = colorHex;
    Utils::Logger::instance().debug(
        m_name + " color set to " + m_color, "Light");
}

const std::string& Light::getColor() const { return m_color; }

// ── State Pattern  ────────────────────────────────────────────────────────

void Light::changeState(std::unique_ptr<State::IDeviceState> newState) {
    if (m_state) m_state->onExit();
    m_state = std::move(newState);
    if (m_state) m_state->onEnter();
}

State::IDeviceState* Light::getCurrentState() const {
    return m_state.get();
}

} // namespace Devices
} // namespace SmartHome
