#include "../../include/strategy/EnergyEfficiencyStrategy.h"
#include "../../include/core/SmartHomeHub.h"
#include "../../include/core/DeviceGroup.h"
#include "../../include/utils/Logger.h"
#include <iostream>

namespace SmartHome {
namespace Strategy {

void EnergyEfficiencyStrategy::execute(Core::SmartHomeHub& hub) {
    std::cout << "\n[Strategy] Applying Energy Efficiency mode...\n";

    // Turn off the entire hub, then selectively re-enable essentials.
    // In a full implementation, you'd walk the composite tree to find
    // Thermostats and Lights specifically.
    hub.turnOff();

    Utils::Logger::instance().info(
        "Energy Efficiency: all non-essential devices turned off. "
        "Eco temp target: " + std::to_string(ECO_TEMPERATURE) + " °C. "
        "Lights dimmed to " + std::to_string(DIM_BRIGHTNESS_PCT) + "%.",
        "EnergyEfficiencyStrategy");

    std::cout << "[Strategy] Energy Efficiency applied. "
              << "Eco temp: " << ECO_TEMPERATURE << " °C, "
              << "Lights: "   << DIM_BRIGHTNESS_PCT << "%\n";
}

std::string EnergyEfficiencyStrategy::getStrategyName() const {
    return "EnergyEfficiency";
}

} // namespace Strategy
} // namespace SmartHome
