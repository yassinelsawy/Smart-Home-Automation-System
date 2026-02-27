#include "../../include/devices/BrandBHalogenLight.h"
#include <algorithm>
#include <iostream>
using namespace std;


BrandBHalogenLight::BrandBHalogenLight(){
    brightness = 100;
}

BrandBHalogenLight::BrandBHalogenLight(string id, string name, string brand)
    : id(id), name(name), brand(brand) {}

void BrandBHalogenLight::turnOn()  { cout << "[BrandBHalogenLight] " << name << " ON\n";  }

void BrandBHalogenLight::turnOff() { cout << "[BrandBHalogenLight] " << name << " OFF\n"; }

int  BrandBHalogenLight::adjustBrightness(int level) {
    brightness = max(0, min(100, level));
    cout << "[BrandBHalogenLight] brightness -> " << brightness << "%\n";
    return brightness;
}

string BrandBHalogenLight::getType() { return "BrandB Halogen Light"; }
