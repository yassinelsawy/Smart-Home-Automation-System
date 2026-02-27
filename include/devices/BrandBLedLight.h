#pragma once
#include "Light.h"
#include <string>
using namespace std;

class BrandBLedLight : public Light {
    string id, name, brand;
    int brightness;
public:
    BrandBLedLight();
    BrandBLedLight(string id, string name, string brand);

    void turnOn() override;
    void turnOff() override;
    int adjustBrightness(int level) override;
    string getType() override;
};
