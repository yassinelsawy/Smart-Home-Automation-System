#include "../../include/state/InactiveState.h"
#include "../../include/utils/Logger.h"
#include <iostream>

namespace SmartHome {
namespace State {

void InactiveState::onEnter() {
    Utils::Logger::instance().debug("Entered InactiveState", "State");
}

void InactiveState::onExit() {
    Utils::Logger::instance().debug("Exited InactiveState", "State");
}

void InactiveState::handleTurnOn() {
    std::cout << "[InactiveState] Turning ON -> ActiveState.\n";
    // The Device context should change state to ActiveState after calling this.
}

void InactiveState::handleTurnOff() {
    std::cout << "[InactiveState] Device is already OFF.\n";
}

std::string InactiveState::getStateName() const { return "Inactive"; }

} // namespace State
} // namespace SmartHome
