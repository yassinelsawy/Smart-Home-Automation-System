#pragma once
#include <string>
#include<iostream>
#include "core/SmartHomeHub.h"

class IMode{
public:
    virtual void applyMode(SmartHomeHub* hub) = 0;
    virtual string getModeName() = 0;
    virtual ~IMode() = default;
};
