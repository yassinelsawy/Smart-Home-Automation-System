#include "../../include/adapter/LegacyDevice.h"
#include <string>

namespace SmartHome {
namespace Adapter {

LegacyDevice::LegacyDevice(const std::string& deviceName)
    : m_deviceName(deviceName)
{}

void LegacyDevice::legacyPowerToggle(bool on) {
    m_powered = on;
}

void LegacyDevice::legacySetValue(int channel, int value) {
    if (channel >= 0 && channel < 8) {
        m_channels[channel] = value;
    }
}

int LegacyDevice::legacyReadChannel(int channel) const {
    if (channel >= 0 && channel < 8) {
        return m_channels[channel];
    }
    return -1;
}

std::string LegacyDevice::legacyGetInfo() const {
    return "LegacyDevice[" + m_deviceName
         + "] powered=" + (m_powered ? "true" : "false");
}

} // namespace Adapter
} // namespace SmartHome
