
#include "SmartComponent.h"
#include "ISubject.h"
#include <string>
#include <vector>
using namespace std;

class SmartDevice : public SmartComponent, public ISubject {
    string id, name, brand, DeviceStatus, location;
    vector<IObserver*> observers;
    DeviceState* currentState;
public:
    void turnOn() override;
    void turnOff() override;
    string getName() override;
    string getId() override;
    string getStatus() override; // devicestatus
    void setLocation(string l) {}
    void attach(IObserver* o){}
    void detach(IObserver* o){}
    void notify(){}

};