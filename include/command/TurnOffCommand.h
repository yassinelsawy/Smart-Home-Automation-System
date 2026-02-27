#pragma once

#include "ICommand.h"
#include "../core/SmartDevice.h"
#include <string>

class TurnOffCommand : public ICommand {
    SmartDevice* m_device;
public:
    TurnOffCommand(SmartDevice* device);
    void execute() override;
    void undo()    override;
};

