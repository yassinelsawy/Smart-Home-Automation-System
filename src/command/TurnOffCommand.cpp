#include "../../include/command/TurnOffCommand.h"
#include "../../include/utils/Logger.h"

namespace SmartHome {
namespace Command {

TurnOffCommand::TurnOffCommand(
    std::shared_ptr<Core::SmartComponent> receiver)
    : m_receiver(std::move(receiver))
{}

void TurnOffCommand::execute() {
    m_receiver->turnOff();
    Utils::Logger::instance().info(
        "Executed: " + getDescription(), "TurnOffCommand");
}

void TurnOffCommand::undo() {
    m_receiver->turnOn();
    Utils::Logger::instance().info(
        "Undone: "    + getDescription(), "TurnOffCommand");
}

std::string TurnOffCommand::getDescription() const {
    return "TurnOff(" + m_receiver->getName() + ")";
}

} // namespace Command
} // namespace SmartHome
