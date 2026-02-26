#pragma once

#include "DeviceGroup.h"
#include "SmartComponent.h"
#include "SmartDeviceFactory.h"
#include "AutomationEngine.h"
#include "IMode.h"
#include "ICommand.h"
#include <string>
#include <vector>
#include <map>

class SmartHomeHub {
    vector<SmartComponent*> devices;
    map<string, vector<SmartComponent*>> devicesByZone; // e.g., "Floor 1" -> [Room1, Room2]
    SmartDeviceFactory* deviceFactory;
    AutomationEngine* automationEngine;
    IMode* currentMode;
public:
    SmartHomeHub(const string& hubName);
    SmartDevice* createDevice(const string& type, const string& id, const string& name, const string& brand);
    void addDevice(SmartComponent* device, const string& zone);
    void removeDevice(SmartComponent* device);
    void controlDevice(const string& deviceId, const string& action);
    void getStatus() const;
    void setMode(IMode* mode);
    void executeAutomation(ICommand* command);
    map<string, vector<SmartComponent*>> getDevicesByZone() const;
    void printHierarchy() const;

};
