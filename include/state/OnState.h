#pragma once
#include "IDeviceState.h"

class OnState : public IDeviceState {
    int brightnessLevel;
public:
    OnState();
    void turnOn(SmartDevice* device) override;
    void turnOff(SmartDevice* device) override;
    void dim(SmartDevice* device, int level) override;
    string getStateName() const override;
};