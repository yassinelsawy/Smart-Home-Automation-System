#include "../../include/core/SmartHomeHub.h"
#include "../../include/utils/Logger.h"
#include <iostream>
#include <string>

namespace SmartHome {
namespace Core {

SmartHomeHub::SmartHomeHub(const std::string& hubName)
    : DeviceGroup(hubName)
{}

void SmartHomeHub::getStatus() const {
    std::cout << "======================================\n";
    std::cout << "  Smart Home Hub: " << m_name << "\n";
    std::cout << "  Total Floors/Groups: " << childCount() << "\n";
    std::cout << "======================================\n";
    for (std::size_t i = 0; i < childCount(); ++i) {
        getChild(i)->getStatus();
    }
    std::cout << "======================================\n";
}

// ── Strategy Pattern ─────────────────────────────────────────────────────

void SmartHomeHub::setAutomationStrategy(
    std::unique_ptr<Strategy::IAutomationStrategy> strategy)
{
    m_strategy = std::move(strategy);
    if (m_strategy) {
        Utils::Logger::instance().info(
            "Strategy set: " + m_strategy->getStrategyName(), "SmartHomeHub");
    }
}

void SmartHomeHub::executeAutomation() {
    if (m_strategy) {
        Utils::Logger::instance().info(
            "Executing strategy: " + m_strategy->getStrategyName(),
            "SmartHomeHub");
        m_strategy->execute(*this);
    } else {
        Utils::Logger::instance().warning(
            "No automation strategy set.", "SmartHomeHub");
    }
}

// ── Utility ──────────────────────────────────────────────────────────────

void SmartHomeHub::printHierarchy(int depth) const {
    std::string indent(static_cast<std::size_t>(depth * 2), ' ');
    std::cout << indent << "[HUB] " << m_name << "\n";
    for (std::size_t i = 0; i < childCount(); ++i) {
        auto* child = getChild(i);
        if (child->isComposite()) {
            std::cout << indent << "  [GROUP] " << child->getName() << "\n";
        } else {
            std::cout << indent << "  [DEVICE] " << child->getName() << "\n";
        }
    }
}

} // namespace Core
} // namespace SmartHome
