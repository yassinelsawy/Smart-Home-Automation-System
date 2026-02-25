#include "../../include/core/SmartComponent.h"
#include <stdexcept>

namespace SmartHome {
namespace Core {

SmartComponent::SmartComponent(const std::string& name)
    : m_name(name) {}

const std::string& SmartComponent::getName() const { return m_name; }

bool SmartComponent::isEnabled() const { return m_enabled; }
void SmartComponent::setEnabled(bool enabled) { m_enabled = enabled; }

bool SmartComponent::isComposite() const { return false; }

// Default no-op composite management (leaves override via SmartDevice,
// composites override via DeviceGroup)
void SmartComponent::add(std::shared_ptr<SmartComponent> /*component*/) {
    throw std::logic_error("add() not supported on a leaf SmartComponent");
}

void SmartComponent::remove(std::shared_ptr<SmartComponent> /*component*/) {
    throw std::logic_error("remove() not supported on a leaf SmartComponent");
}

SmartComponent* SmartComponent::getChild(std::size_t /*index*/) {
    return nullptr;
}

} // namespace Core
} // namespace SmartHome
