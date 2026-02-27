#include "../../include/devices/BrandALedLight.h"


#include <iostream>

using namespace std;

BrandALedLight::BrandALedLight(string id, string name, string brand) : id(id), name(name), brand(brand){}

void BrandALedLight::turnOn() {
    cout << "Brand A LED Light " << name << " is turned ON." << endl;
}

void BrandALedLight::turnOff() {
    cout << "Brand A LED Light " << name << " is turned OFF." << endl;
}

int BrandALedLight::adjustBrightness(int level) {
    brightness = max(0, min(100, level));
    cout << "Brand A LED Light " << name << " brightness set to " << brightness << "%" << endl;
    return brightness;
}

string BrandALedLight::getType() {
    return "Brand A LED Light";
}