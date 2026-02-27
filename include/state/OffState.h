#pragma once
#include "IDeviceState.h"

class OffState : public IDeviceState {
public:
    void turnOn(SmartDevice* device) override;
    void turnOff(SmartDevice* device) override;
    void dim(SmartDevice* device, int level) override;
    string getStateName() const override;
};