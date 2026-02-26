
#include <iostream>
#include <string>
// #include "SmartDevice.h"

using namespace std;

class IDeviceState {
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual void dim(SmartDevice* device, int level) = 0;
    virtual string getStatus() = 0;
    virtual ~IDeviceState() = default;
};
