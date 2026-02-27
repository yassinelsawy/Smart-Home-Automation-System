#pragma once
#include "DeviceGroup.h"
#include <string>
using namespace std;

class FunctionalGroup : public DeviceGroup {
    string functionType;
public:
    FunctionalGroup() = default;
    FunctionalGroup(string gID, string gName, string funcType);
    string getFunctionType() const;
};
