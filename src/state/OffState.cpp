#include "../../include/state/OffState.h"
#include "../../include/core/SmartDevice.h"
#include <iostream>
using namespace std;

void OffState::turnOn(SmartDevice* /*device*/) {
    cout << "[OffState] Turning ON device.\n";
}

void OffState::turnOff(SmartDevice* /*device*/) {
    cout << "[OffState] Device is already OFF.\n";
}

void OffState::dim(SmartDevice* /*device*/, int /*level*/) {
    cout << "[OffState] Cannot dim - device is OFF.\n";
}

string OffState::getStateName() const { return "Off"; }
