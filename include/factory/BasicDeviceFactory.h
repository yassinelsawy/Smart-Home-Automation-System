#include "SmartDeviceFactory.h"
#include <iostream>

using namespace std;
class BasicDeviceFactory : public SmartDeviceFactory {

public:
    Light* createLight(string type) override{}
    Thermostat* createThermostat(string type) override{}
    Camera* createCamera(string type) override{}
    MotionSensor* createMotionSensor() override{}
    DoorLock* createDoorLock() override{}
    
};
