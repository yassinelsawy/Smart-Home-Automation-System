
#include "../../include/adapter/ExternalDevice.h"
#include <iostream>
using namespace std;

void ExternalDevice::connect() {
    isConnected = true;
    rawState    = "connected";
    cout << "[ExternalDevice:" << vendorName << "] Connected via " << protocolType << ".\n";
}

void ExternalDevice::disconnect() {
    isConnected = false;
    rawState    = "disconnected";
    cout << "[ExternalDevice:" << vendorName << "] Disconnected.\n";
}

void ExternalDevice::sendCommand(const string& command) {
    if (isConnected) {
        rawState = command;
        cout << "[ExternalDevice:" << vendorName << "] Executing command: " << command << "\n";
    } else {
        cout << "[ExternalDevice:" << vendorName << "] Not connected. Cannot send command.\n";
    }
}

string ExternalDevice::getStatus() const {
    return isConnected ? "Connected (state=" + rawState + ")" : "Disconnected";
}

