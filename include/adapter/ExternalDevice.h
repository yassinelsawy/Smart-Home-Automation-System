#pragma once

#include <string>
using namespace std;
class ExternalDevice {
    string externalId, vendorName, protocolType;
    bool isConnected;
public:
    ExternalDevice(string id, string vendor, string protocol){}
    void connect() {};
    void disconnect() {};
    void sendCommand(string command) {};
    string getStatus(){};
};