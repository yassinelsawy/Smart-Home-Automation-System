#include "../../include/command/TurnOnCommand.h"
#include "../../include/core/SmartDevice.h"
using namespace std;

TurnOnCommand::TurnOnCommand(SmartDevice* device) : m_device(device) {}

void TurnOnCommand::execute() {
    m_device->turnOn();
}

void TurnOnCommand::undo() {
    m_device->turnOff();
}
