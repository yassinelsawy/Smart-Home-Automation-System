#pragma once
#include "ICommand.h"
#include "../devices/Thermostat.h"

class SetTemperatureCommand : public ICommand {
    Thermostat* thermostat;
    double targetTemp;
    double previousTemp;
public:
    SetTemperatureCommand(Thermostat* t, double temp)
        : thermostat(t), targetTemp(temp), previousTemp(0.0) {}
    void execute() override;
    void undo()    override;
};
