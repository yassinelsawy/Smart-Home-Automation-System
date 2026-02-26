#include "PremiumLedLight.h"


#include <iostream>

using namespace std;

PremiumLedLight::PremiumLedLight(string id, string name, string brand) : id(id), name(name), brand(brand){}

void PremiumLedLight::turnOn() {
    cout << "Premium LED Light " << name << " is turned ON." << endl;
}

void PremiumLedLight::turnOff() {
    cout << "Premium LED Light " << name << " is turned OFF." << endl;
}

int PremiumLedLight::adjustBrightness(int level) {
    if (level < 0 || level > 100) {
        cout << "Brightness level must be between 0 and 100." << endl;
        return brightness;
    }
    brightness = level;
    cout << "Premium LED Light " << name << " brightness adjusted to " << brightness << "%." << endl;
    return brightness;
}

string PremiumLedLight::getType() {
    return "Premium LED Light";
}