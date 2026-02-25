#include "../../include/state/ActiveState.h"
#include "../../include/utils/Logger.h"
#include <iostream>

namespace SmartHome {
namespace State {

void ActiveState::onEnter() {
    Utils::Logger::instance().debug("Entered ActiveState", "State");
}

void ActiveState::onExit() {
    Utils::Logger::instance().debug("Exited ActiveState", "State");
}

void ActiveState::handleTurnOn() {
    std::cout << "[ActiveState] Device is already ON.\n";
}

void ActiveState::handleTurnOff() {
    std::cout << "[ActiveState] Turning OFF -> InactiveState.\n";
    // The Device context should change state to InactiveState after calling this.
}

std::string ActiveState::getStateName() const { return "Active"; }

} // namespace State
} // namespace SmartHome
