#pragma once

#include <string>
using namespace std;

class Light {
public:
    Light() = default;
    virtual ~Light() = default;
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual int adjustBrightness(int level) = 0;  // 0-100
    virtual string getType() = 0;
};

