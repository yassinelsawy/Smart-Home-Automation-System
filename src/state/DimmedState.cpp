#include "../../include/state/DimmedState.h"
#include "../../include/core/SmartDevice.h"
#include <iostream>
using namespace std;

DimmedState::DimmedState() : brightnessLevel(50) {}

DimmedState::DimmedState(int level) : brightnessLevel(level) {}

int DimmedState::getBrightnessLevel() const { return brightnessLevel; } 

void DimmedState::turnOn(SmartDevice* /*device*/) {
    brightnessLevel = 100;
    cout << "[DimmedState] Turning ON - restoring full brightness.\n";
}

void DimmedState::turnOff(SmartDevice* /*device*/) {
    cout << "[DimmedState] Turning OFF device.\n";
}

void DimmedState::dim(SmartDevice* /*device*/, int level) {
    brightnessLevel = level;
    cout << "[DimmedState] Adjusting brightness to " << level << ".\n";
}

string DimmedState::getStateName() const { return "Dimmed"; }
