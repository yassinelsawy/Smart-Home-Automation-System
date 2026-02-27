#pragma once
#include "IDeviceState.h"

class DimmedState : public IDeviceState {
    int brightnessLevel;
public:
    DimmedState();
    DimmedState(int level);
    int  getBrightnessLevel() const;
    void turnOn(SmartDevice* device) override;
    void turnOff(SmartDevice* device) override;
    void dim(SmartDevice* device, int level) override;
    string getStateName() const override;
};