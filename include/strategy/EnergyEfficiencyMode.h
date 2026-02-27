#pragma once

#include "IMode.h"

class EnergyEfficiencyMode : public IMode {
    int maxAllowedDevices;
    int autoShutdownDelay;
public:
    void applyMode(SmartHomeHub* hub) override;
    string getModeName() override;
};