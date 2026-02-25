#include "IDeviceState.h"

class OffState : public IDeviceState {
public:
    void turnOn() override;
    void turnOff() override;
    void dim(SmartDevice* device, int level) override;
    string getStatus() override;
};