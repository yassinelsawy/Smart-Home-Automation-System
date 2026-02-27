#include "Client.h"

#include "core/SmartHomeHub.h"
#include "core/SmartDevice.h"
#include "core/FloorGroup.h"
#include "core/RoomGroup.h"
#include "core/FunctionalGroup.h"

#include "devices/BrandALedLight.h"
#include "devices/BrandBLedLight.h"
#include "devices/BrandASmartThermoA.h"
#include "devices/BrandAWiredSCam.h"
#include "devices/BrandBWirelessSCam.h"
#include "devices/DoorLock.h"
#include "devices/MotionSensor.h"

#include "factory/BrandAFactory.h"
#include "factory/BrandBFactory.h"

#include "command/AutomationEngine.h"
#include "command/TurnOnCommand.h"
#include "command/TurnOffCommand.h"
#include "command/SetTemperatureCommand.h"

#include "state/OnState.h"
#include "state/OffState.h"
#include "state/DimmedState.h"

#include "strategy/ComfortMode.h"
#include "strategy/EnergyEfficiencyMode.h"

#include "adapter/ExternalDevice.h"
#include "adapter/ExternalDeviceAdapter.h"

#include "observer/Observer.h"

#include <iostream>
#include <string>
using namespace std;

static void section(const string& title) {
    cout << "\n========================================\n";
    cout << title << "\n";
    cout << "========================================\n";
}

Client::Client() : hub(nullptr) {}

Client::~Client() { delete hub; }

void Client::setupSystem() {
    hub = new SmartHomeHub("My Smart Home");
}

void Client::run() {

    // =========================================================================
    // 1. ABSTRACT FACTORY PATTERN
    // =========================================================================
    section("1. Abstract Factory Pattern");

    BrandAFactory factoryA;
    BrandBFactory factoryB;

    Light* brandALight = factoryA.createLight("LED");
    Light* brandBLight = factoryB.createLight("LED");
    Camera* brandACam = factoryA.createCamera("Wired");
    Camera* brandBCam = factoryB.createCamera("Wireless");
    Thermostat* brandATherm = factoryA.createThermostat("A");
    Thermostat* brandBTherm = factoryB.createThermostat("A");
    MotionSensor* sensor = factoryB.createMotionSensor();
    DoorLock* dlock = factoryB.createDoorLock();

    brandALight->turnOn();
    brandALight->adjustBrightness(80);
    cout << "BrandA light type: " << brandALight->getType() << "\n";

    brandBLight->turnOn();
    cout << "BrandB light type: " << brandBLight->getType() << "\n";

    brandATherm->setTargetTemperature(22.5);
    brandATherm->setMode(ThermoMode::HEATING);
    cout << "BrandA thermo target: " << brandATherm->getTargetTemperature() << " C\n";

    brandBTherm->setTargetTemperature(20.0);

    brandACam->startRecording();
    brandACam->enableNightVision();
    brandBCam->startRecording();
    cout << "BrandA cam recording: " << (brandACam->isRecording() ? "YES" : "NO") << "\n";

    dlock->setPin("1234");
    dlock->lock();
    cout << "Door locked: " << (dlock->isLocked() ? "YES" : "NO") << "\n";

    sensor->setSensitivity(7);
    cout << "Motion detected: " << (sensor->detectMotion() ? "YES" : "NO") << "\n";

    // =========================================================================
    // 2. COMPOSITE PATTERN
    // =========================================================================
    section("2. Composite Pattern");

    SmartDevice livingLight("L001", "Living Room Light", "BrandA");
    SmartDevice hallSensor("S001", "Hall Sensor", "BrandA");
    SmartDevice frontLock("DL01", "Front Door Lock", "BrandA");
    SmartDevice bedroomLight("L002", "Bedroom Light", "BrandB");
    SmartDevice bedThermo("T001", "Bedroom Thermostat", "BrandB");

    FloorGroup groundFloor("F001", "Ground Floor", 0);
    RoomGroup livingRoom("R001", "Living Room", "Lounge");
    RoomGroup hallway("R002", "Hallway", "Corridor");
    FloorGroup firstFloor("F002", "First Floor", 1);
    RoomGroup bedroom("R003", "Bedroom", "Master");
    FunctionalGroup secZone("FG01", "Security Zone", "Security");

    livingRoom.add(&livingLight);
    hallway.add(&hallSensor);
    hallway.add(&frontLock);
    bedroom.add(&bedroomLight);
    bedroom.add(&bedThermo);

    groundFloor.add(&livingRoom);
    groundFloor.add(&hallway);
    firstFloor.add(&bedroom);

    secZone.add(&hallSensor);
    secZone.add(&frontLock);

    hub->addDevice(&groundFloor, "Ground");
    hub->addDevice(&firstFloor, "First");
    hub->addDevice(&secZone, "Security");

    cout << "Ground floor number: " << groundFloor.getFloorNumber() << "\n";
    cout << "First floor number: " << firstFloor.getFloorNumber() << "\n";
    cout << "Living room type: " << livingRoom.getRoomType() << "\n";
    cout << "Hallway type: " << hallway.getRoomType() << "\n";
    cout << "Security zone func: " << secZone.getFunctionType() << "\n";

    cout << "\n--- [Leaf] Turn on Living Room Light individually ---\n";
    livingLight.turnOn();
    cout << livingLight.getName() << " -> " << livingLight.getStatus() << "\n";

    cout << "\n--- [Composite] Turn on entire Ground Floor (propagates down) ---\n";
    groundFloor.turnOn();
    cout << livingLight.getName() << " -> " << livingLight.getStatus() << "\n";
    cout << hallSensor.getName() << " -> " << hallSensor.getStatus() << "\n";
    cout << frontLock.getName() << " -> " << frontLock.getStatus() << "\n";

    cout << "\n--- [Composite] Turn off just the Hallway (Living Room unaffected) ---\n";
    hallway.turnOff();
    cout << livingLight.getName() << " -> " << livingLight.getStatus() << "\n";
    cout << hallSensor.getName() << " -> " << hallSensor.getStatus() << "\n";
    cout << frontLock.getName() << " -> " << frontLock.getStatus() << "\n";

    cout << "\n--- [Cross-cut] Turn on Security Zone (spans rooms/floors) ---\n";
    secZone.turnOn();
    cout << hallSensor.getName() << " -> " << hallSensor.getStatus() << "\n";
    cout << frontLock.getName() << " -> " << frontLock.getStatus() << "\n";

    cout << "\n--- [Hub] Full hub status by zone ---\n";
    hub->getStatus();

    // =========================================================================
    // 3. COMMAND PATTERN
    // =========================================================================
    section("3. Command Pattern");

    AutomationEngine invoker;

    TurnOnCommand cmdOn(&livingLight);
    TurnOffCommand cmdOff(&bedroomLight);
    SetTemperatureCommand cmdTemp(brandATherm, 25.0);

    invoker.execute(&cmdOn);
    cout << "Living light after TurnOn: " << livingLight.getStatus() << "\n";

    invoker.execute(&cmdTemp);
    cout << "Thermostat after SetTemperature: " << brandATherm->getTargetTemperature() << " C\n";

    invoker.undoLast();
    cout << "Thermostat after undo: " << brandATherm->getTargetTemperature() << " C\n";

    invoker.execute(&cmdOff);
    cout << "Bedroom light after TurnOff: " << bedroomLight.getStatus() << "\n";

    // =========================================================================
    // 4. STATE PATTERN
    // =========================================================================
    section("4. State Pattern");

    OnState onState;
    DimmedState dimState(60);
    OffState offState;

    cout << "OnState name: " << onState.getStateName() << "\n";
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

    cout << "--- Triggering state changes (engine reacts to each) ---\n";
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
    hub->setMode(&comfortMode);

    cout << "Applying: " << ecoMode.getModeName() << "\n";
    hub->setMode(&ecoMode);

    // =========================================================================
    // 7. ADAPTER PATTERN
    // =========================================================================
    section("7. Adapter Pattern");

    ExternalDevice legacyHVAC("EXT-001", "VendorXYZ HVAC", "RS-485");
    ExternalDeviceAdapter adapter(&legacyHVAC, "v2.1", true);

    adapter.turnOn();
    adapter.control("dim");
    cout << "Adapter status: " << adapter.getStatus() << "\n";
    cout << "Adapter name: " << adapter.getName() << "\n";
    adapter.turnOff();

    hub->addDevice(&adapter, "External");
    hub->controlDevice("EXT-001", "on");

    // =========================================================================
    section("Demo Complete");
    cout << "All 7 patterns demonstrated successfully.\n\n";

    delete brandALight;
    delete brandBLight;
    delete brandACam;
    delete brandBCam;
    delete brandATherm;
    delete brandBTherm;
    delete sensor;
    delete dlock;
}
