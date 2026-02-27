#include "../../include/factory/BrandAFactory.h"
#include "../../include/devices/BrandALedLight.h"
#include "../../include/devices/BrandAHalogenLight.h"
#include "../../include/devices/BrandAWiredSCam.h"
#include "../../include/devices/BrandAWirelessSCam.h"
#include "../../include/devices/BrandASmartThermoA.h"
#include "../../include/devices/BrandASmartThermoB.h"
#include "../../include/devices/MotionSensor.h"
#include "../../include/devices/DoorLock.h"

#include <iostream>
#include <string>
using namespace std;

// BrandAFactory creates Brand-A (premium tier) concrete devices.

Light* BrandAFactory::createLight(string type) {
    if (type == "Halogen")
        return new BrandAHalogenLight("", "", "BrandA");
    return new BrandALedLight();  // default: LED
}

Thermostat* BrandAFactory::createThermostat(string type) {
    if (type == "B")
        return new BrandASmartThermoB();
    return new BrandASmartThermoA();  // default: ThermoA
}

Camera* BrandAFactory::createCamera(string type) {
    if (type == "Wireless")
        return new BrandAWirelessSCam();
    return new BrandAWiredSCam();  // default: Wired
}

MotionSensor* BrandAFactory::createMotionSensor() {
    return new MotionSensor();
}

DoorLock* BrandAFactory::createDoorLock() {
    return new DoorLock();
}


