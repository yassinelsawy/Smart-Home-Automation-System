#pragma once

#include <string>
using namespace std;

class ExternalDevice {
    string externalId;
    string vendorName;
    string protocolType;
    bool   isConnected;
    string rawState;
public:
    ExternalDevice(string id, string vendor, string protocol)
        : externalId(id), vendorName(vendor), protocolType(protocol),
          isConnected(false), rawState("unknown") {}

    void   connect();
    void   disconnect();
    void   sendCommand(const string& command);
    string getStatus() const;

    string getExternalId()    const { return externalId;    }
    string getVendorName()    const { return vendorName;    }
    string getProtocolType()  const { return protocolType;  }
    bool   getIsConnected()   const { return isConnected;   }
    string getRawState()      const { return rawState;      }
};