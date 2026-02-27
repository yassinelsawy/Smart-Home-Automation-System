#include "../../include/core/SmartHomeHub.h"
#include "../../include/command/AutomationEngine.h"
#include "../../include/strategy/IMode.h"
#include "../../include/command/ICommand.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

SmartHomeHub::SmartHomeHub(const string& /*hubName*/) {
    deviceFactory    = nullptr;
    automationEngine = new AutomationEngine();
    currentMode      = nullptr;
}

SmartHomeHub::~SmartHomeHub() {
    delete automationEngine;
}

void SmartHomeHub::setFactory(SmartDeviceFactory* factory) {
    deviceFactory = factory;
}

void SmartHomeHub::addDevice(SmartComponent* device, const string& zone) {
    devicesByZone[zone].push_back(device);
    devices.push_back(device);
}

void SmartHomeHub::removeDevice(SmartComponent* device) {
    for (auto& pair : devicesByZone) {
        auto& vec = pair.second;
        vec.erase(remove(vec.begin(), vec.end(), device), vec.end());
    }
    devices.erase(remove(devices.begin(), devices.end(), device), devices.end());
}

void SmartHomeHub::controlDevice(const string& /*deviceId*/, const string& action) {
    for (auto* d : devices) {
        if (action == "on")  d->turnOn();
        if (action == "off") d->turnOff();
    }
}

void SmartHomeHub::getStatus() const {
    cout << "Smart Home Hub Status:\n";
    for (const auto& pair : devicesByZone) {
        cout << "Zone: " << pair.first << "\n";
        for (const auto* device : pair.second)
            cout << "  - " << device->getStatus() << "\n";
    }
}

void SmartHomeHub::setMode(IMode* mode) {
    currentMode = mode;
    if (currentMode) currentMode->applyMode(this);
}

void SmartHomeHub::executeAutomation(ICommand* command) {
    automationEngine->executeCommand(command);
}

map<string, vector<SmartComponent*>> SmartHomeHub::getDevicesByZone() const {
    return devicesByZone;
}

void SmartHomeHub::printHierarchy() const {
    cout << "=== Smart Home Hierarchy ===\n";
    for (const auto& pair : devicesByZone) {
        cout << "Zone: " << pair.first << "\n";
        for (const auto* device : pair.second)
            cout << "  [" << device->getName() << "]\n";
    }
}
