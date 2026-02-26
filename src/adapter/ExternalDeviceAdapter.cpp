#include "ExternalDeviceAdapter.h"
#include <iostream>
using namespace std;

ExternalDeviceAdapter::ExternalDeviceAdapter(ExternalDevice* device, string version, bool synced) : externalDevice(device), adapterVersion(version), protocolSynced(synced) {}
void ExternalDeviceAdapter::turnOn() {
    externalDevice->connect();
}
void ExternalDeviceAdapter::turnOff() {
    externalDevice->disconnect();
}
string ExternalDeviceAdapter::getName() {
    return "External Device Adapter for " + externalDevice->getStatus();
}
string ExternalDeviceAdapter::getId() {
    return "Adapter-" + externalDevice->getStatus();
}
string ExternalDeviceAdapter::getStatus() {
    return externalDevice->getStatus();
}
