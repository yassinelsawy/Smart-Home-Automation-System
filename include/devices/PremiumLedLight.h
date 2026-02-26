
#include "Light.h"

using namespace std;
class PremiumLedLight : public Light {
    string id, name, brand;
    int brightness;
public:
    PremiumLedLight() {}
    PremiumLedLight(string id, string name, string brand) {}
    void turnOn() override ;
    void turnOff() override ;
    int adjustBrightness(int level) override ;
    string getType() override ;
    
};