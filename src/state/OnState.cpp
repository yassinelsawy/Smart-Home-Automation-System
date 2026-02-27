#include "../../include/state/OnState.h"
#include "../../include/core/SmartDevice.h"
#include <iostream>
using namespace std;

OnState::OnState() : brightnessLevel(100) {}

void OnState::turnOn(SmartDevice* /*device*/) {
    cout << "[OnState] Device is already ON.\n";
}

void OnState::turnOff(SmartDevice* /*device*/) {
    cout << "[OnState] Turning OFF device.\n";
}

void OnState::dim(SmartDevice* /*device*/, int level) {
    brightnessLevel = level;
    cout << "[OnState] Dimming to level " << level << ".\n";
}

string OnState::getStateName() const { return "On"; }
