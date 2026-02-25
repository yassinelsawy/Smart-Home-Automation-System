#pragma once

#include "IDeviceFactory.h"

namespace SmartHome {
namespace Factory {

/**
 * @brief Creates premium-tier smart home devices.
 *
 * Devices are constructed with enhanced defaults (higher
 * sensor sensitivity, full-spectrum lighting, tighter
 * temperature control).
 *
 * Design Pattern role: Abstract Factory – Concrete Factory B
 */
class PremiumDeviceFactory : public IDeviceFactory {
public:
    PremiumDeviceFactory() = default;

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
