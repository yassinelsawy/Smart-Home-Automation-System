#include "../../include/strategy/ComfortMode.h"
#include "../../include/core/SmartHomeHub.h"
#include <iostream>
using namespace std;

void ComfortMode::applyMode(SmartHomeHub* hub) {
    cout << "[ComfortMode] Applying comfort settings (temp=" << tempLevel
         << ", brightness=" << brightnessLevel << ").\n";
    if (hub) {
        for (auto* device : hub->getDevicesByZone().begin()->second)
            device->turnOn();
    }
}

string ComfortMode::getModeName() { return "Comfort"; }
