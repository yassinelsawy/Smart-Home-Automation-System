#pragma once

#include "IMode.h"

class EnergyEfficiencyMode : IMode {
    int maxAllowedDevices;
    int autoShutdownDelay;
public:
    void applyMode(SmartHomeHub hub) override;
    string getModeName() override;
};