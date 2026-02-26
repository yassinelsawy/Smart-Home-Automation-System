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
    virtual Light* createLight() const = 0;
    virtual Thermostat* createThermostat() const = 0;
    virtual Camera* createCamera() const = 0;
    virtual MotionSensor* createMotionSensor() const = 0;
    virtual DoorLock* createDoorLock() const = 0;
};

