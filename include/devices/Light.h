#pragma once

#include "../core/SmartDevice.h"
#include "../state/IDeviceState.h"
#include <memory>
#include <string>
using namespace std;

class Light {
public:
    Light();
    ~Light() = default;
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual int adjustBrightness(int level) = 0; // 0-100
    virtual string getType();
};

