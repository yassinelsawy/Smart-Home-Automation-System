#include "../../include/factory/BrandBFactory.h"
#include "../../include/devices/BrandBLedLight.h"
#include "../../include/devices/BrandBHalogenLight.h"
#include "../../include/devices/BrandBWiredSCam.h"
#include "../../include/devices/BrandBWirelessSCam.h"
#include "../../include/devices/BrandBSmartThermoA.h"
#include "../../include/devices/BrandBSmartThermoB.h"
#include "../../include/devices/MotionSensor.h"
#include "../../include/devices/DoorLock.h"

#include <string>
using namespace std;

// BrandBFactory creates Brand-B (basic tier) concrete devices.

Light* BrandBFactory::createLight(string type) {
    if (type == "Halogen")
        return new BrandBHalogenLight();
    return new BrandBLedLight();  // default: LED
}

Thermostat* BrandBFactory::createThermostat(string type) {
    if (type == "B")
        return new BrandBSmartThermoB();
    return new BrandBSmartThermoA();  // default: ThermoA
}

Camera* BrandBFactory::createCamera(string type) {
    if (type == "Wireless")
        return new BrandBWirelessSCam();
    return new BrandBWiredSCam();  // default: Wired
}

MotionSensor* BrandBFactory::createMotionSensor() {
    return new MotionSensor();
}

DoorLock* BrandBFactory::createDoorLock() {
    return new DoorLock();
}

