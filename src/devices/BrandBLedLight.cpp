#include "../../include/devices/BrandBLedLight.h"
#include <algorithm>
#include <iostream>
using namespace std;



BrandBLedLight::BrandBLedLight(){
    brightness = 100;
}

BrandBLedLight::BrandBLedLight(string id, string name, string brand)
    : id(id), name(name), brand(brand) {}

void BrandBLedLight::turnOn()  { cout << "[BrandBLedLight] " << name << " ON\n";  }

void BrandBLedLight::turnOff() { cout << "[BrandBLedLight] " << name << " OFF\n"; }

int  BrandBLedLight::adjustBrightness(int level) {
    brightness = max(0, min(100, level));
    cout << "[BrandBLedLight] brightness -> " << brightness << "%\n";
    return brightness;
}

string BrandBLedLight::getType() { return "BrandB LED Light"; }
