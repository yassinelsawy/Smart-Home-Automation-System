#pragma once
#include <iostream>
#include <string>

using namespace std;

class SmartDevice;

class IDeviceState {
public:
    virtual void turnOn(SmartDevice* device)                    = 0;
    virtual void turnOff(SmartDevice* device)                   = 0;
    virtual void dim(SmartDevice* device, int level)            = 0;
    virtual string getStateName() const = 0;
    virtual ~IDeviceState() = default;
};
