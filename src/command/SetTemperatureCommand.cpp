#include "../../include/command/SetTemperatureCommand.h"
#include "../../include/utils/Logger.h"

namespace SmartHome {
namespace Command {

SetTemperatureCommand::SetTemperatureCommand(
    std::shared_ptr<Devices::Thermostat> thermostat,
    double                                newTemperature)
    : m_thermostat(std::move(thermostat))
    , m_newTemperature(newTemperature)
{}

void SetTemperatureCommand::execute() {
    m_previousTemperature = m_thermostat->getTargetTemperature();
    m_thermostat->setTargetTemperature(m_newTemperature);
    Utils::Logger::instance().info(
        "Executed: " + getDescription(), "SetTemperatureCommand");
}

void SetTemperatureCommand::undo() {
    m_thermostat->setTargetTemperature(m_previousTemperature);
    Utils::Logger::instance().info(
        "Undone: "    + getDescription(), "SetTemperatureCommand");
}

std::string SetTemperatureCommand::getDescription() const {
    return "SetTemperature(" + m_thermostat->getName()
         + ", " + std::to_string(m_newTemperature) + " °C)";
}

} // namespace Command
} // namespace SmartHome
