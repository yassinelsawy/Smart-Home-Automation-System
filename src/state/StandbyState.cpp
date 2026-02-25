#include "../../include/state/StandbyState.h"
#include "../../include/utils/Logger.h"
#include <iostream>

namespace SmartHome {
namespace State {

void StandbyState::onEnter() {
    Utils::Logger::instance().debug("Entered StandbyState", "State");
}

void StandbyState::onExit() {
    Utils::Logger::instance().debug("Exited StandbyState", "State");
}

void StandbyState::handleTurnOn() {
    std::cout << "[StandbyState] Waking up -> ActiveState.\n";
}

void StandbyState::handleTurnOff() {
    std::cout << "[StandbyState] Powering off -> InactiveState.\n";
}

std::string StandbyState::getStateName() const { return "Standby"; }

} // namespace State
} // namespace SmartHome
