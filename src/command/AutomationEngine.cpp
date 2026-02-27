
#include "../../include/command/ICommand.h"
#include "../../include/core/SmartDevice.h"
#include "../../include/observer/Observer.h"
#include "../../include/command/AutomationEngine.h"
#include <iostream>
#include <algorithm>
using namespace std;

// Called automatically by SmartDevice::notify() whenever a device state changes.
// Logs the event and optionally executes queued commands.
void AutomationEngine::update(SmartDevice* device) {
    cout << "[AutomationEngine] Device '" << device->getName()
         << "' changed state to: " << device->getStatus() << "\n";

    // Track this device if not already monitored
    if (find(monitoredDevices.begin(), monitoredDevices.end(), device)
            == monitoredDevices.end()) {
        monitoredDevices.push_back(device);
    }
}

// Immediately execute a command and record it in history
void AutomationEngine::executeCommand(ICommand* command) {
    command->execute();
    historyCommands.push_back(command);
}

// Wrapper for executeCommand (alternative name for convenience)
void AutomationEngine::execute(ICommand* command) {
    executeCommand(command);
}

// Undo the last executed command
void AutomationEngine::undoLast() {
    if (!historyCommands.empty()) {
        ICommand* lastCommand = historyCommands.back();
        lastCommand->undo();
        historyCommands.pop_back();
    } else {
        cout << "[AutomationEngine] No commands to undo.\n";
    }
}

// Enqueue a command for later execution (without running it immediately)
void AutomationEngine::addCommand(ICommand* command) {
    historyCommands.push_back(command);
}
