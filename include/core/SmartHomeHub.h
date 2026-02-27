#pragma once

#include "DeviceGroup.h"
#include "SmartComponent.h"
#include "../factory/SmartDeviceFactory.h"
#include "../command/AutomationEngine.h"
#include "../command/ICommand.h"
#include <string>
#include <vector>
#include <map>

class IMode;  // forward declaration – avoids circular include with strategy headers

class SmartHomeHub {
    vector<SmartComponent*> devices;
    map<string, vector<SmartComponent*>> devicesByZone;
    SmartDeviceFactory* deviceFactory;
    AutomationEngine* automationEngine;
    IMode* currentMode;
public:
    SmartHomeHub(const string& hubName);
    ~SmartHomeHub();
    void addDevice(SmartComponent* device, const string& zone);
    void removeDevice(SmartComponent* device);
    void controlDevice(const string& deviceId, const string& action);
    void getStatus() const;
    void setMode(IMode* mode);
    void setFactory(SmartDeviceFactory* factory);
    void executeAutomation(ICommand* command);
    map<string, vector<SmartComponent*>> getDevicesByZone() const;
    void printHierarchy() const;
};
