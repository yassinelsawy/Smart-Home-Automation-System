#include "../../include/core/FunctionalGroup.h"

#include <iostream>
using namespace std;


FunctionalGroup::FunctionalGroup(string gID, string gName, string funcType)
    : DeviceGroup(gID, gName), functionType(funcType) {}

string FunctionalGroup::getFunctionType() const {return functionType;}
