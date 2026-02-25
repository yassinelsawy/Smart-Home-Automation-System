#include "../../include/strategy/ComfortStrategy.h"
#include "../../include/core/SmartHomeHub.h"
#include "../../include/utils/Logger.h"
#include <iostream>

namespace SmartHome {
namespace Strategy {

const char* ComfortStrategy::WARM_WHITE_HEX = "#FFD700";

void ComfortStrategy::execute(Core::SmartHomeHub& hub) {
    std::cout << "\n[Strategy] Applying Comfort mode...\n";

    hub.turnOn();

    Utils::Logger::instance().info(
        "Comfort mode: lights at " + std::to_string(COMFORT_BRIGHTNESS) + "% ("
        + std::string(WARM_WHITE_HEX) + "), thermostat at "
        + std::to_string(COMFORT_TEMP) + " °C.",
        "ComfortStrategy");

    std::cout << "[Strategy] Comfort mode applied. "
              << "Lights: " << COMFORT_BRIGHTNESS << "% warm-white, "
              << "Temp: "   << COMFORT_TEMP        << " °C.\n";
}

std::string ComfortStrategy::getStrategyName() const {
    return "Comfort";
}

} // namespace Strategy
} // namespace SmartHome
