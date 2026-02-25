#include "../../include/command/TurnOnCommand.h"
#include "../../include/utils/Logger.h"

namespace SmartHome {
namespace Command {

TurnOnCommand::TurnOnCommand(
    std::shared_ptr<Core::SmartComponent> receiver)
    : m_receiver(std::move(receiver))
{}

void TurnOnCommand::execute() {
    m_receiver->turnOn();
    Utils::Logger::instance().info(
        "Executed: " + getDescription(), "TurnOnCommand");
}

void TurnOnCommand::undo() {
    m_receiver->turnOff();
    Utils::Logger::instance().info(
        "Undone: "    + getDescription(), "TurnOnCommand");
}

std::string TurnOnCommand::getDescription() const {
    return "TurnOn(" + m_receiver->getName() + ")";
}

} // namespace Command
} // namespace SmartHome
