#include "../../include/strategy/EnergyEfficiencyMode.h"
#include "../../include/core/SmartHomeHub.h"
#include <iostream>
using namespace std;

void EnergyEfficiencyMode::applyMode(SmartHomeHub* hub) {
    cout << "[EnergyEfficiencyMode] Applying energy saving (maxDevices=" << maxAllowedDevices
         << ", shutdownDelay=" << autoShutdownDelay << "s).\n";
    if (hub) {
        for (auto& zone : hub->getDevicesByZone())
            for (auto* device : zone.second)
                device->turnOff();
    }
}

string EnergyEfficiencyMode::getModeName() { return "EnergyEfficiency"; }
