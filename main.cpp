/**
 * @file main.cpp
 * @brief Smart Home Automation System - design patterns demonstration.
 *
 *  1. Abstract Factory  - BasicDeviceFactory / PremiumDeviceFactory
 *  2. Composite         - FloorGroup / RoomGroup / FunctionalGroup hierarchy
 *  3. Command           - TurnOn/Off, SetTemperature, undo
 *  4. State             - OnState / OffState / DimmedState transitions
 *  5. Observer          - AutomationEngine reacts to device changes
 *  6. Strategy          - ComfortMode / EnergyEfficiencyMode
 *  7. Adapter           - ExternalDevice via ExternalDeviceAdapter
 */

#include "include/core/SmartHomeHub.h"
#include "include/core/SmartDevice.h"
#include "include/core/FloorGroup.h"
#include "include/core/RoomGroup.h"
#include "include/core/FunctionalGroup.h"

#include "include/devices/BrandALedLight.h"
#include "include/devices/BrandBLedLight.h"
#include "include/devices/BrandASmartThermoA.h"
#include "include/devices/BrandAWiredSCam.h"
#include "include/devices/BrandBWirelessSCam.h"
#include "include/devices/DoorLock.h"
#include "include/devices/MotionSensor.h"

#include "include/factory/BrandBFactory.h"
#include "include/factory/BrandAFactory.h"

#include "include/command/AutomationEngine.h"
#include "include/command/TurnOnCommand.h"
#include "include/command/TurnOffCommand.h"
#include "include/command/SetTemperatureCommand.h"
#include "include/command/AutomationEngine.h"

#include "include/state/OnState.h"
#include "include/state/OffState.h"
#include "include/state/DimmedState.h"

#include "include/strategy/ComfortMode.h"
#include "include/strategy/EnergyEfficiencyMode.h"

#include "include/adapter/ExternalDevice.h"
#include "include/adapter/ExternalDeviceAdapter.h"

#include "include/observer/Observer.h"

#include <iostream>
#include <string>
using namespace std;

// ---------------------------------------------------------------------------
void section(const string& title) {
    cout << "\n========================================\n";
    cout << "  " << title << "\n";
    cout << "========================================\n";
}

// // Minimal concrete observer for the demo
// class ConsoleObserver : public Observer {
//     string label;
// public:
//     explicit ConsoleObserver(string lbl) : label(move(lbl)) {}
//     void update(SmartDevice* device) override {
//         cout << "[Observer:" << label << "] '"
//              << device->getName() << "' -> " << device->getStatus() << "\n";
//     }
// };

// ---------------------------------------------------------------------------
int main() {

    // =========================================================================
    // 1. ABSTRACT FACTORY
    // =========================================================================
    section("1. Abstract Factory Pattern");

    BrandAFactory BrandAFactory;
    BrandBFactory   BrandBFactory;

    Light* BrandALight = BrandAFactory.createLight("LED");
    Light* BrandBLight = BrandBFactory.createLight("LED");
    Camera* BrandACam = BrandAFactory.createCamera("Wired");
    Camera* BrandBCam = BrandBFactory.createCamera("Wireless");
    Thermostat* BrandATherm = BrandAFactory.createThermostat("A");
    Thermostat* BrandBTherm = BrandBFactory.createThermostat("A");
    MotionSensor* sensor = BrandBFactory.createMotionSensor();
    DoorLock* dlock = BrandBFactory.createDoorLock();

    BrandALight->turnOn();
    BrandALight->adjustBrightness(80);
    cout << "Premium light type : " << BrandALight->getType() << "\n";

    BrandBLight->turnOn();
    cout << "Basic light type : " << BrandBLight->getType() << "\n";

    BrandATherm->setTargetTemperature(22.5);
    BrandATherm->setMode(ThermoMode::HEATING);
    cout << "Premium thermostat target : " << BrandATherm->getTargetTemperature() << " C\n";

    BrandBTherm->setTargetTemperature(20.0);

    BrandACam->startRecording();
    BrandACam->enableNightVision();
    BrandBCam->startRecording();
    cout << "Premium cam recording: " << (BrandACam->isRecording() ? "YES" : "NO") << "\n";

    dlock->setPin("1234");
    dlock->lock();
    cout << "Door locked: " << (dlock->isLocked() ? "YES" : "NO") << "\n";

    sensor->setSensitivity(7);
    bool motionFound = sensor->detectMotion();
    cout << "Motion detected: " << (motionFound ? "YES" : "NO") << "\n";

    // =========================================================================
    // 2. COMPOSITE PATTERN
    // =========================================================================
    section("2. Composite Pattern");

    SmartDevice livingLight("L001", "Living Room Light", "BrandA");
    SmartDevice bedroomLight("L002", "Bedroom Light", "BrandB");
    SmartDevice hallSensor  ("S001", "Hall Sensor", "BrandA");
    SmartDevice frontLock   ("DL01", "Front Door Lock", "BrandA");
    SmartDevice bedThermo   ("T001", "Bedroom Thermostat","BrandB");

    SmartHomeHub hub("My Smart Home");

    FloorGroup groundFloor ("F001", "Ground Floor",  0);
    RoomGroup livingRoom ("R001", "Living Room", "Lounge");
    RoomGroup hallway ("R002", "Hallway", "Corridor");
    FloorGroup firstFloor ("F002", "First Floor", 1);
    RoomGroup bedroom ("R003", "Bedroom", "Master");
    FunctionalGroup secZone ("FG01", "Security Zone", "Security");

    livingRoom.add(&livingLight);
    hallway.add(&hallSensor);
    hallway.add(&frontLock);
    bedroom.add(&bedroomLight);
    bedroom.add(&bedThermo);
    secZone.add(&hallSensor);
    secZone.add(&frontLock);

    groundFloor.add(&livingRoom);
    groundFloor.add(&hallway);
    firstFloor.add(&bedroom);

    hub.addDevice(&groundFloor, "Ground");
    hub.addDevice(&firstFloor, "First");
    hub.addDevice(&secZone, "Security");

    cout << "Security zone type: " << secZone.getFunctionType() << "\n";

    cout << "\n--- Turning on Ground Floor (propagates to all children) ---\n";
    groundFloor.turnOn();

    cout << "\n--- Hub status by zone ---\n";
    hub.getStatus();

    // =========================================================================
    // 3. COMMAND PATTERN
    // =========================================================================
    section("3. Command Pattern");

    AutomationEngine invoker;

    TurnOnCommand cmdOn (&livingLight);
    TurnOffCommand cmdOff (&bedroomLight);
    SetTemperatureCommand cmdTemp(BrandATherm, 25.0);

    invoker.execute(&cmdOn);
    cout << "Living light status: " << livingLight.getStatus() << "\n";

    invoker.execute(&cmdTemp);
    cout << "Thermostat after set: " << BrandATherm->getTargetTemperature() << " C\n";

    invoker.undoLast();
    cout << "Thermostat after undo: " << BrandATherm->getTargetTemperature() << " C\n";

    invoker.execute(&cmdOff);
    cout << "Bedroom light status: " << bedroomLight.getStatus() << "\n";

    // =========================================================================
    // 4. STATE PATTERN
    // =========================================================================
    section("4. State Pattern");

    OnState onState;
    DimmedState dimState(60);
    OffState offState;

    cout << "OnState name: " << onState.getStateName()  << "\n";
    cout << "DimmedState name: " << dimState.getStateName() << "\n";
    cout << "OffState name: " << offState.getStateName() << "\n";

    SmartDevice lamp("DEV1", "Smart Lamp", "BrandA");
    cout << "\nLamp initial: " << lamp.getStatus() << "\n";
    lamp.turnOn();
    cout << "After turnOn: " << lamp.getStatus() << "\n";
    lamp.dim(40);
    cout << "After dim(40): " << lamp.getStatus() << "\n";
    lamp.turnOff();
    cout << "After turnOff: " << lamp.getStatus() << "\n";

    // =========================================================================
    // 5. OBSERVER PATTERN
    // =========================================================================
    section("5. Observer Pattern");

    AutomationEngine engine;

    livingLight.attach(&engine);
    hallSensor.attach(&engine);
    bedroomLight.attach(&engine);

    cout << "--- Triggering device changes ---\n";
    livingLight.turnOn();
    livingLight.turnOff();
    hallSensor.turnOn();
    bedroomLight.turnOn();

    // =========================================================================
    // 6. STRATEGY PATTERN
    // =========================================================================
    section("6. Strategy Pattern");

    ComfortMode comfortMode;
    EnergyEfficiencyMode ecoMode;

    cout << "Applying: " << comfortMode.getModeName() << "\n";
    hub.setMode(&comfortMode);

    cout << "Applying: " << ecoMode.getModeName() << "\n";
    hub.setMode(&ecoMode);

    // =========================================================================
    // 7. ADAPTER PATTERN
    // =========================================================================
    section("7. Adapter Pattern");

    ExternalDevice legacyHVAC("EXT-001", "VendorXYZ HVAC", "RS-485");
    ExternalDeviceAdapter adapter(&legacyHVAC, "v2.1", true);

    adapter.turnOn();
    adapter.control("dim");
    cout << "Adapter status: " << adapter.getStatus() << "\n";
    cout << "Adapter name: " << adapter.getName()   << "\n";
    adapter.turnOff();

    hub.addDevice(&adapter, "External");
    hub.controlDevice("EXT-001", "on");

    // =========================================================================
    section("Demo Complete");
    cout << "All 7 patterns demonstrated successfully.\n\n";

    delete BrandALight;
    delete BrandBLight;
    delete BrandACam;
    delete BrandBCam;
    delete BrandATherm;
    delete BrandBTherm;
    delete sensor;
    delete dlock;

    return 0;
}