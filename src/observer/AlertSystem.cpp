#include "../../include/observer/AlertSystem.h"
// AlertSystem: Concrete Observer implementation
#include "../../include/utils/Logger.h"
#include <iostream>

namespace SmartHome {
namespace Observer {

AlertSystem::AlertSystem(const std::string& systemName)
    : m_systemName(systemName)
{}

void AlertSystem::onEvent(const std::string& source,
                           const std::string& event) {
    std::string alert = "[ALERT][" + m_systemName + "] "
                      + source + " -> " + event;
    m_alertHistory.push_back(alert);
    std::cout << alert << "\n";
    Utils::Logger::instance().warning(alert, "AlertSystem");
}

void AlertSystem::clearAlerts() {
    m_alertHistory.clear();
}

void AlertSystem::printAlertHistory() const {
    std::cout << "=== Alert History (" << m_systemName << ") ===\n";
    for (const auto& a : m_alertHistory) {
        std::cout << "  " << a << "\n";
    }
    std::cout << "=== End of Alerts ===\n";
}

std::size_t AlertSystem::alertCount() const {
    return m_alertHistory.size();
}

} // namespace Observer
} // namespace SmartHome
