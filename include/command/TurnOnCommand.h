#pragma once

#include "ICommand.h"
#include "../core/SmartDevice.h"
#include <memory>
#include <string>


class TurnOnCommand : public ICommand {
public:
    TurnOnCommand(SmartDevice* device);
    void execute() override;
    void undo() override;
};
