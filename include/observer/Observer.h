#pragma once
#include <iostream>
#include <string>

class SmartDevice;  // forward declaration

class Observer {
public:
    virtual void update(SmartDevice* device) = 0;
    virtual ~Observer() = default;
};

