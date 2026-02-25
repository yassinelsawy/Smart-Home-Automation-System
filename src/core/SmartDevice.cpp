#include "../../include/core/SmartDevice.h"
#include "../../include/utils/Logger.h"
#include <iostream>

namespace SmartHome {
namespace Core {

SmartDevice::SmartDevice(const std::string& name,
                         const std::string& deviceId,
                         const std::string& location)
    : SmartComponent(name)
    , m_deviceId(deviceId)
    , m_location(location)
{}

void SmartDevice::turnOn() {
    m_enabled = true;
    Utils::Logger::instance().info(
        "[" + m_name + "] turned ON", "SmartDevice");
}

void SmartDevice::turnOff() {
    m_enabled = false;
    Utils::Logger::instance().info(
        "[" + m_name + "] turned OFF", "SmartDevice");
}

void SmartDevice::getStatus() const {
    std::cout << "Device: " << m_name
              << " | ID: "       << m_deviceId
              << " | Location: " << m_location
              << " | Status: "   << (m_enabled ? "ON" : "OFF")
              << "\n";
}

const std::string& SmartDevice::getDeviceId() const { return m_deviceId; }
const std::string& SmartDevice::getLocation()  const { return m_location;  }

void SmartDevice::setLocation(const std::string& location) {
    m_location = location;
}

} // namespace Core
} // namespace SmartHome
