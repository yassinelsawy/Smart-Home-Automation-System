#pragma once

#include "IMode.h"

class ComfortMode : public IMode {
    int tempLevel;
    int brightnessLevel;
public:
    void applyMode(SmartHomeHub* hub) override;
    string getModeName() override;
};