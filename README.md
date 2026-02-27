# Smart Home Automation System

A C++17 demonstration project that showcases **7 classic Gang-of-Four design patterns** applied to a realistic smart-home domain.  
The system manages lights, thermostats, cameras, motion sensors, and door locks across floors, rooms, and functional zones.

---

## Table of Contents

- [Overview](#overview)
- [Design Patterns](#design-patterns)
- [Project Structure](#project-structure)
- [Prerequisites](#prerequisites)
- [Build Instructions](#build-instructions)
- [Running the Demo](#running-the-demo)
- [Pattern Details](#pattern-details)

---

## Overview

The Smart Home Automation System models a connected home where:

- Multiple **device brands** (Brand A and Brand B) manufacture lights, thermostats, cameras, motion sensors, and door locks.
- Devices are organized in a **hierarchical composite** (floors → rooms → devices) and cross-cutting **functional zones** (e.g., a Security Zone).
- A central **hub** orchestrates devices, applies operational **modes**, and listens to **events**.
- Individual device actions can be queued, executed, and **undone** via commands.
- Devices transition through **states** (on / dimmed / off).
- A legacy external device is integrated through an **adapter**.

---

## Design Patterns

| # | Pattern          | Key Classes |
|---|------------------|-------------|
| 1 | Abstract Factory  | `SmartDeviceFactory`, `BrandAFactory`, `BrandBFactory` |
| 2 | Composite         | `SmartComponent`, `SmartDevice`, `DeviceGroup`, `FloorGroup`, `RoomGroup`, `FunctionalGroup` |
| 3 | Command           | `ICommand`, `TurnOnCommand`, `TurnOffCommand`, `SetTemperatureCommand`, `AutomationEngine` |
| 4 | State             | `IDeviceState`, `OnState`, `OffState`, `DimmedState` |
| 5 | Observer          | `Observer`, `Subject`, `AutomationEngine` |
| 6 | Strategy          | `IMode`, `ComfortMode`, `EnergyEfficiencyMode`, `SmartHomeHub` |
| 7 | Adapter           | `ExternalDevice`, `ExternalDeviceAdapter` |

---

## Project Structure

```
Smart-Home-Automation-System/
├── CMakeLists.txt          # Build configuration
├── main.cpp                # Demo entry point (all 7 patterns)
├── include/
│   ├── adapter/            # Adapter pattern interfaces & adapter
│   ├── command/            # Command pattern (commands + invoker)
│   ├── core/               # Composite core (SmartDevice, groups, hub)
│   ├── devices/            # Concrete device types per brand
│   ├── factory/            # Abstract Factory interfaces & concrete factories
│   ├── observer/           # Observer / Subject interfaces
│   ├── state/              # State pattern (On, Off, Dimmed)
│   ├── strategy/           # Strategy pattern (Comfort, EnergyEfficiency)
│   └── utils/              # Shared utilities
└── src/
    ├── adapter/
    ├── command/
    ├── core/
    ├── devices/
    ├── factory/
    ├── state/
    └── strategy/
```

---

## Prerequisites

| Tool | Minimum version |
|------|----------------|
| C++ compiler with C++17 support | GCC 7 / Clang 5 / MSVC 2017 |
| CMake | 3.17 |

---

## Build Instructions

```bash
# 1. Clone the repository
git clone https://github.com/yassinelsawy/Smart-Home-Automation-System.git
cd Smart-Home-Automation-System

# 2. Configure (out-of-source build)
cmake -S . -B build

# 3. Compile
cmake --build build

# The executable is placed in build/bin/SmartHome
```

> **Windows (MSVC):** open the generated `.sln` in Visual Studio, or run  
> `cmake --build build --config Release`.

---

## Running the Demo

```bash
./build/bin/SmartHome
```

The program walks through each of the seven patterns in sequence and prints labelled output to the console, for example:

```
========================================
  1. Abstract Factory Pattern
========================================
BrandALedLight turned ON
Premium light type : LED
...

========================================
  Demo Complete
========================================
All 7 patterns demonstrated successfully.
```

---

## Pattern Details

### 1 · Abstract Factory
`SmartDeviceFactory` declares factory methods (`createLight`, `createCamera`, `createThermostat`, `createMotionSensor`, `createDoorLock`).  
`BrandAFactory` and `BrandBFactory` implement these methods and return brand-specific concrete products, ensuring that incompatible products are never mixed.

### 2 · Composite
`SmartComponent` is the common interface for both leaf devices (`SmartDevice`) and container groups (`DeviceGroup`).  
- `FloorGroup` – groups rooms on the same floor.  
- `RoomGroup` – groups devices within a single room.  
- `FunctionalGroup` – cross-cutting zone (e.g., Security) that spans multiple rooms.  
Operations such as `turnOn()` propagate recursively through the entire tree.

### 3 · Command
`ICommand` exposes `execute()` and `undo()`.  
`AutomationEngine` (the *invoker*) maintains a history stack so that the last executed command can be undone with `undoLast()`.  
Concrete commands: `TurnOnCommand`, `TurnOffCommand`, `SetTemperatureCommand`.

### 4 · State
`SmartDevice` delegates state-dependent behaviour to an `IDeviceState` object.  
Transitions:  
`OffState` → (turnOn) → `OnState` → (dim) → `DimmedState` → (turnOff) → `OffState`.

### 5 · Observer
`Subject` maintains a list of `Observer` instances and calls `update()` on each when a device changes.  
`AutomationEngine` implements `Observer` and reacts to device events (e.g., triggers rules when a sensor turns on).

### 6 · Strategy
`SmartHomeHub` holds an `IMode*` and delegates its `apply()` call at runtime.  
- `ComfortMode` – prioritises user comfort settings.  
- `EnergyEfficiencyMode` – applies energy-saving adjustments.  
Swapping modes requires no changes to the hub itself.

### 7 · Adapter
`ExternalDevice` represents a legacy third-party device with its own interface.  
`ExternalDeviceAdapter` wraps it and implements the `SmartComponent` interface, making it a first-class citizen in the hub without modifying the original class.
