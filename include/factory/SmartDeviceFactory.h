#pragma once

#include "../devices/Light.h"
#include "../devices/Thermostat.h"
#include "../devices/Camera.h"
#include "../devices/MotionSensor.h"
#include "../devices/DoorLock.h"

#include <string>
using namespace std;

class SmartDeviceFactory {
public:
    virtual ~SmartDeviceFactory() = default;
    virtual Light* createLight(string type) = 0;
    virtual Thermostat* createThermostat(string type) = 0;
    virtual Camera* createCamera(string type) = 0;
    virtual MotionSensor* createMotionSensor() = 0;
    virtual DoorLock* createDoorLock() = 0;
};

