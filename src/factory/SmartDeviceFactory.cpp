#include "../devices/Light.h"
#include "../devices/Thermostat.h"
#include "../devices/Camera.h"
#include "../devices/MotionSensor.h"
#include "../devices/DoorLock.h"

#include "SmartDeviceFactory.h"

Light* SmartDeviceFactory::createLight() const {
    
}

Thermostat* SmartDeviceFactory::createThermostat(string type) const {
    return new Thermostat(type);
}

Camera* SmartDeviceFactory::createCamera(string type) const {
    return new Camera(type);
}

MotionSensor* SmartDeviceFactory::createMotionSensor() const {
    return new MotionSensor();
}

DoorLock* SmartDeviceFactory::createDoorLock() const {
    return new DoorLock();
}