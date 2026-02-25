#include "IDeviceState.h"

class OnState : public IDeviceState {
    int brightnessLevel;
public:
    OnState() : brightnessLevel(100) {}
    void turnOn() override;
    void turnOff() override;
    void dim(SmartDevice* device, int level) override;
    string getStatus() override;
};