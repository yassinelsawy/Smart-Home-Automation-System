#include "../../include/command/SetTemperatureCommand.h"
#include <iostream>
using namespace std;

void SetTemperatureCommand::execute() {
    previousTemp = thermostat->getTargetTemperature();
    thermostat->setTargetTemperature(targetTemp);
}

void SetTemperatureCommand::undo() {
    thermostat->setTargetTemperature(previousTemp);
}
