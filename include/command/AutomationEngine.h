#pragma once

#include "ICommand.h"
#include "../core/SmartDevice.h"
#include "../observer/Observer.h"
#include <string>
#include <vector>

class AutomationEngine : public Observer {
    vector<SmartDevice*> monitoredDevices;   
    vector<ICommand*>    historyCommands;    
public:

    void update(SmartDevice* device) override;

    void addCommand(ICommand* command);
    void executeCommand(ICommand* command);
    void execute(ICommand* command);    // wrapper for executeCommand
    void undoLast();                     // undo the last executed command
};
