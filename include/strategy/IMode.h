#pragma once
#include <string>
#include <iostream>
using namespace std;

class SmartHomeHub;  // forward declaration

class IMode{
public:
    virtual void applyMode(SmartHomeHub* hub) = 0;
    virtual string getModeName() = 0;
    virtual ~IMode() = default;
};
