#include "../../include/adapter/LegacyDeviceAdapter.h"
#include "../../include/utils/Logger.h"
#include <stdexcept>
#include <string>

namespace SmartHome {
namespace Adapter {

LegacyDeviceAdapter::LegacyDeviceAdapter(
    std::shared_ptr<LegacyDevice> legacyDevice)
    : m_legacyDevice(std::move(legacyDevice))
{}

// ── ISmartHomeProtocol ────────────────────────────────────────────────────

void LegacyDeviceAdapter::powerOn() {
    m_legacyDevice->legacyPowerToggle(true);
    Utils::Logger::instance().info(
        "LegacyDeviceAdapter: powerOn() -> legacyPowerToggle(true)",
        "Adapter");
}

void LegacyDeviceAdapter::powerOff() {
    m_legacyDevice->legacyPowerToggle(false);
    Utils::Logger::instance().info(
        "LegacyDeviceAdapter: powerOff() -> legacyPowerToggle(false)",
        "Adapter");
}

void LegacyDeviceAdapter::setParameter(const std::string& key,
                                        const std::string& value) {
    // Map generic key->value to legacy channel->int
    // Convention: key is "channel_N", value is the numeric string
    if (key.rfind("channel_", 0) == 0) {
        int ch  = std::stoi(key.substr(8));
        int val = std::stoi(value);
        m_legacyDevice->legacySetValue(ch, val);
        Utils::Logger::instance().debug(
            "LegacyDeviceAdapter: setParameter ch=" + std::to_string(ch)
            + " val=" + std::to_string(val), "Adapter");
    } else {
        Utils::Logger::instance().warning(
            "LegacyDeviceAdapter: unknown param key=" + key, "Adapter");
    }
}

std::string LegacyDeviceAdapter::queryStatus() const {
    return m_legacyDevice->legacyGetInfo();
}

std::string LegacyDeviceAdapter::getProtocolVersion() const {
    return "SmartHomeProtocol/1.0 (via LegacyAdapter)";
}

} // namespace Adapter
} // namespace SmartHome
