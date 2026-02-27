#pragma once

#include "../core/SmartDevice.h"
#include "ExternalDevice.h"
#include <string>

using namespace std;

class ExternalDeviceAdapter : public SmartDevice {
private:
    ExternalDevice* externalDevice;
    string          adapterVersion;
    bool            protocolSynced;

    string translateCommand(const string& cmd) const;

public:
    ExternalDeviceAdapter(ExternalDevice* device, string version, bool synced)
        : SmartDevice(device ? device->getExternalId() : "ext-0",
                      device ? device->getVendorName() : "External",
                      "Adapter"),
          externalDevice(device), adapterVersion(version), protocolSynced(synced) {}

    void   turnOn()              override;
    void   turnOff()             override;
    string getName()       const override;
    string getId()         const override;
    string getStatus()     const override;
    void   control(const string& command);
};

