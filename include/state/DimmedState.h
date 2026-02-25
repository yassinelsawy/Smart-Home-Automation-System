#include "IDeviceState.h"

class DimmedState : public IDeviceState {
    int brightnessLevel;
public:
    DimmedState(int level) : brightnessLevel(level) {}
    void turnOn() override;
    void turnOff() override;
    void dim(SmartDevice* device, int level) override;
    string getStatus() override;
};