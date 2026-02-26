#include "ICommand.h"
#include "SmartDevice.h"

using namespace std;

TurnOffCommand::TurnOffCommand(SmartDevice* device) : m_device(device) {}

void TurnOffCommand::execute() {
    m_device->turnOff();
}

void TurnOffCommand::undo() {
    m_device->turnOn();
}