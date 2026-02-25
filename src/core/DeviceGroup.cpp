#include "../../include/core/DeviceGroup.h"
#include <algorithm>
#include <iostream>

namespace SmartHome {
namespace Core {

DeviceGroup::DeviceGroup(const std::string& name)
    : SmartComponent(name) {}

// ── SmartComponent interface ──────────────────────────────────────────────

void DeviceGroup::turnOn() {
    m_enabled = true;
    for (auto& child : m_children) {
        child->turnOn();
    }
}

void DeviceGroup::turnOff() {
    m_enabled = false;
    for (auto& child : m_children) {
        child->turnOff();
    }
}

void DeviceGroup::getStatus() const {
    std::cout << "Group [" << m_name << "] | Children: "
              << m_children.size() << "\n";
    for (const auto& child : m_children) {
        child->getStatus();
    }
}

// ── Composite management ──────────────────────────────────────────────────

void DeviceGroup::add(std::shared_ptr<SmartComponent> component) {
    m_children.push_back(std::move(component));
}

void DeviceGroup::remove(std::shared_ptr<SmartComponent> component) {
    m_children.erase(
        std::remove(m_children.begin(), m_children.end(), component),
        m_children.end());
}

SmartComponent* DeviceGroup::getChild(std::size_t index) {
    if (index < m_children.size()) {
        return m_children[index].get();
    }
    return nullptr;
}

std::size_t DeviceGroup::childCount() const {
    return m_children.size();
}

} // namespace Core
} // namespace SmartHome
