#pragma once

#include "../core/SmartDevice.h"
#include "ExternalDevice.h"
#include <string>

using namespace std;

class ExternalDeviceAdapter : public SmartDevice {
private:
    ExternalDevice* externalDevice;
    string adapterVersion; bool protocolSynced;
public:
    ExternalDeviceAdapter(ExternalDevice* device, string version, bool synced)  {}
    void turnOn() override;
    void turnOff() override;
    string getName() override;
    string getId() override;
    string getStatus() override;
    // void attach(IObserver* o) override;
    // void detach(IObserver* o) override;
    // void notify() override;
};

