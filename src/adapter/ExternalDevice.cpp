
#include "../../include/adapter/ExternalDeviceAdapter.h"
#include <iostream>
#include <string>

using namespace std;

ExternalDevice::ExternalDevice(string id, string vendor, string protocol) : externalId(id), vendorName(vendor), protocolType(protocol), isConnected(false) {}
void ExternalDevice::connect() {
    isConnected = true;
    cout << "ExternalDevice " << externalId << " connected." << endl;
}
void ExternalDevice::disconnect() {
    isConnected = false;
    cout << "ExternalDevice " << externalId << " disconnected." << endl;
}
void ExternalDevice::sendCommand(string command) {
    if (isConnected) {
        cout << "ExternalDevice " << externalId << " executing command: " << command << endl;
    } else {
        cout << "ExternalDevice " << externalId << " is not connected. Cannot send command." << endl;
    }
}
string ExternalDevice::getStatus() {
    return isConnected ? "Connected" : "Disconnected";
}

