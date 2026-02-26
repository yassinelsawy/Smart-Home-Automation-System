#include "SmartDeviceFactory.h"
#include "PremiumDeviceFactory.h"
#include "../devices/PremiumLedLight.h"

#include <iostream>
#include <string>
using namespace std;


Light* PremiumDeviceFactory::createLight(){
    return new PremiumLedLight();
}

Thermostat* PremiumDeviceFactory::createThermostat() {
    return new Thermostat();
}

Camera* PremiumDeviceFactory::createCamera() {
    return new Camera();
}

MotionSensor* PremiumDeviceFactory::createMotionSensor() {
    return new MotionSensor();
}

DoorLock* PremiumDeviceFactory::createDoorLock() {
    return new DoorLock();
}


