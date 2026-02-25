#pragma once

#include "IDeviceFactory.h"

namespace SmartHome {
namespace Factory {

/**
 * @brief Creates standard-tier smart home devices.
 *
 * Devices are constructed with sensible defaults (medium
 * brightness, eco temperature, standard sensitivity).
 *
 * Design Pattern role: Abstract Factory – Concrete Factory A
 */
class BasicDeviceFactory : public IDeviceFactory {
public:
    BasicDeviceFactory() = default;

    std::unique_ptr<Devices::Light>
        createLight(const std::string& name,
                    const std::string& id,
                    const std::string& location) override;

    std::unique_ptr<Devices::Thermostat>
        createThermostat(const std::string& name,
                         const std::string& id,
                         const std::string& location) override;

    std::unique_ptr<Devices::Camera>
        createCamera(const std::string& name,
                     const std::string& id,
                     const std::string& location) override;

    std::unique_ptr<Devices::MotionSensor>
        createMotionSensor(const std::string& name,
                           const std::string& id,
                           const std::string& location) override;

    std::unique_ptr<Devices::DoorLock>
        createDoorLock(const std::string& name,
                       const std::string& id,
                       const std::string& location) override;

    std::string getFactoryName() const override;
};

} // namespace Factory
} // namespace SmartHome
