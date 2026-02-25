#pragma once

#include "ICommand.h"
#include "SmartDevice.h"
#include "IObserver.h"
#include <memory>
#include <stack>
#include <string>
#include <vector>


class AutomationEngine : public IObserver {
    vector<SmartDevice*> monitoredDevices;
    vector<ICommand*> historyCommands;
public:
    void update(SmartDevice* device) override;
    void executeCommand(ICommand* command);
    void addCommand(ICommand* command);

};
