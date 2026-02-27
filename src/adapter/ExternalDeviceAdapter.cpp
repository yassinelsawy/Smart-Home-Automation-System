#include "../../include/adapter/ExternalDeviceAdapter.h"
#include "../../include/adapter/ExternalDevice.h"
#include <iostream>
using namespace std;

string ExternalDeviceAdapter::translateCommand(const string& cmd) const {
    // Translate generic smart home command to vendor-specific protocol
    if (cmd == "on")  return "POWER_ON";
    if (cmd == "off") return "POWER_OFF";
    return cmd;
}

void ExternalDeviceAdapter::turnOn() {
    if (externalDevice) {
        externalDevice->connect();
        externalDevice->sendCommand(translateCommand("on"));
    }
}

void ExternalDeviceAdapter::turnOff() {
    if (externalDevice) {
        externalDevice->sendCommand(translateCommand("off"));
        externalDevice->disconnect();
    }
}

void ExternalDeviceAdapter::control(const string& command) {
    if (externalDevice)
        externalDevice->sendCommand(translateCommand(command));
}

string ExternalDeviceAdapter::getName() const {
    return externalDevice ? externalDevice->getVendorName() + " (Adapter)" : "ExternalDeviceAdapter";
}

string ExternalDeviceAdapter::getId() const {
    return externalDevice ? externalDevice->getExternalId() : "adapter-0";
}

string ExternalDeviceAdapter::getStatus() const {
    return externalDevice ? externalDevice->getStatus() : "No device";
}
