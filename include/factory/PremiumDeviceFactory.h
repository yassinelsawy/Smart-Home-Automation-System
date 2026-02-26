
#include "SmartDeviceFactory.h"
#include <iostream>
using namespace std;


class PremiumDeviceFactory : public SmartDeviceFactory {
public:
    Light* createLight() override;
    Thermostat* createThermostat() override;
    Camera* createCamera() override;
    MotionSensor* createMotionSensor() override;
    DoorLock* createDoorLock() override;
    
};
