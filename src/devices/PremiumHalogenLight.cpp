#include "PremiumHalogenLight.h"

#include <iostream>

using namespace std;

PremiumHalogenLight::PremiumHalogenLight(string id, string name, string brand) : id(id), name(name), brand(brand){}

void PremiumHalogenLight::turnOn() {
    cout << "Premium Halogen Light " << name << " is turned ON." << endl;
}

void PremiumHalogenLight::turnOff() {
    cout << "Premium Halogen Light " << name << " is turned OFF." << endl;
}

int PremiumHalogenLight::adjustBrightness(int level) {
    if (level < 0 || level > 100) {
        cout << "Brightness level must be between 0 and 100." << endl;
        return brightness;
    }
    brightness = level;
    cout << "Premium Halogen Light " << name << " brightness adjusted to " << brightness << "%." << endl;
    return brightness;
}

string PremiumHalogenLight::getType() {
    return "Premium Halogen Light";
}