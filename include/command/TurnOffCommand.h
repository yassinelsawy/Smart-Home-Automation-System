#pragma once

#include "ICommand.h"
#include "../core/SmartDevice.h"
#include <memory>
#include <string>


class TurnOffCommand : public ICommand {
    // SmartDevice* device;
public:
    TurnOffCommand(SmartDevice* device);
    void execute() override;
    void undo() override;
};

