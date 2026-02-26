
#include "ICommand.h"
#include "SmartDevice.h"
#include "IObserver.h"
#include "AutomationEngine.h"
using namespace std;

void AutomationEngine::update(SmartDevice* device) {
    cout << "Device " << device->getName() << " has changed state to " << (device->getStatus() ? "ON" : "OFF") << endl;
}

void AutomationEngine::executeCommand(ICommand* command) {
    command->execute();
    historyCommands.push_back(command);
}

void AutomationEngine::addCommand(ICommand* command) {
    historyCommands.push_back(command);
}
