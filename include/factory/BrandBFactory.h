#pragma once
#include "SmartDeviceFactory.h"
#include <string>
using namespace std;

// BasicDeviceFactory creates Brand-B (basic tier) concrete devices.
class BrandBFactory : public SmartDeviceFactory {
public:
    Light* createLight(string type) override;
    Thermostat* createThermostat(string type) override;
    Camera* createCamera(string type) override;
    MotionSensor* createMotionSensor() override;
    DoorLock* createDoorLock() override;
};
