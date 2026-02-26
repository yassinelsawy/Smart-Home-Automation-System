#include "DeviceGroup.h"
#include "SmartComponent.h"
#include "SmartDeviceFactory.h"
#include "AutomationEngine.h"
#include "IMode.h"
#include "ICommand.h"
#include "SmartHomeHub.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

SmartHomeHub::SmartHomeHub(const string& hubName) {
    deviceFactory = new SmartDeviceFactory();
    automationEngine = new AutomationEngine();
    currentMode = nullptr;
}

SmartDevice* SmartHomeHub::createDevice(const string& type, const string& id, const string& name, const string& brand) {
    if (type == "Light") {
        return deviceFactory->createLight(type);
    } else if (type == "Thermostat") {
        return deviceFactory->createThermostat(type);
    } else if (type == "Camera") {
        return deviceFactory->createCamera(type);
    } else if (type == "MotionSensor") {
        return deviceFactory->createMotionSensor();
    } else if (type == "DoorLock") {
        return deviceFactory->createDoorLock();
    }
    return nullptr;
}

void SmartHomeHub::getStatus() const {
    cout << "Smart Home Hub Status:\n";
    for (const auto& pair : devicesByZone) {
        cout << "Zone: " << pair.first << "\n";
        for (const auto* device : pair.second) {
            cout << "  - " << device->getStatus() << "\n";
        }
    }
}

