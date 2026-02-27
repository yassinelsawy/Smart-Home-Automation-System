#include "../../include/devices/BrandAHalogenLight.h"

#include <iostream>

using namespace std;

BrandAHalogenLight::BrandAHalogenLight(string id, string name, string brand) : id(id), name(name), brand(brand){}

void BrandAHalogenLight::turnOn() {
    cout << "Brand A Halogen Light " << name << " is turned ON." << endl;
}

void BrandAHalogenLight::turnOff() {
    cout << "Brand A Halogen Light " << name << " is turned OFF." << endl;
}

int BrandAHalogenLight::adjustBrightness(int level) {
    brightness = max(0, min(100, level));
    cout << "Brand A Halogen Light " << name << " brightness set to " << brightness << "%" << endl;
    return brightness;
}

string BrandAHalogenLight::getType() {
    return "Brand A Halogen Light";
}