#pragma once
#include "Light.h"
#include <string>
using namespace std;

class BrandALedLight : public Light {
    string id, name, brand;
    int brightness = 0;
public:
    BrandALedLight() = default;
    BrandALedLight(string id, string name, string brand);
    void turnOn() override;
    void turnOff() override;
    int adjustBrightness(int level) override;
    string getType() override;
};
