#include "Light.h"

using namespace std;
class PremiumHalogenLight : public Light {
    string id, name, brand;
    int brightness;
public:
    PremiumHalogenLight(string id, string name, string brand) : id(id), name(name), brand(brand), brightness(0) {}
    void turnOn() override ;
    void turnOff() override ;
    int adjustBrightness(int level) override ;
    string getType() override ;
    
};