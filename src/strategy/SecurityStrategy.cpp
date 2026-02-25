#include "../../include/strategy/SecurityStrategy.h"
#include "../../include/core/SmartHomeHub.h"
#include "../../include/utils/Logger.h"
#include <iostream>

namespace SmartHome {
namespace Strategy {

void SecurityStrategy::execute(Core::SmartHomeHub& hub) {
    std::cout << "\n[Strategy] Applying Security mode...\n";

    // Turn on the whole hub so all devices (cameras, sensors) are active.
    hub.turnOn();

    Utils::Logger::instance().info(
        "Security mode: all devices ON – "
        "cameras recording, door locks engaged.",
        "SecurityStrategy");

    std::cout << "[Strategy] Security mode applied. "
              << "Cameras ON, motion sensors active, doors locked.\n";
}

std::string SecurityStrategy::getStrategyName() const {
    return "Security";
}

} // namespace Strategy
} // namespace SmartHome
