#pragma once
#include "Light.h"
#include <string>
using namespace std;

class BrandBHalogenLight : public Light {
    string id, name, brand;
    int brightness;
public:
    BrandBHalogenLight();
    BrandBHalogenLight(string id, string name, string brand);
    void turnOn() override;
    void turnOff() override;
    int adjustBrightness(int level) override;
    string getType() override;
};
