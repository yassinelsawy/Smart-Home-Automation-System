#pragma once
#include <string>
#include<iostream>
#include "core/SmartHomeHub.h"

class IMode{
public:
    virtual void applyMode(SmartHomeHub hub);
    virtual string getModeName();
};
