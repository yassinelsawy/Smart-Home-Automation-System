#include "../../include/command/CommandInvoker.h"
#include "../../include/utils/Logger.h"
#include <iostream>

namespace SmartHome {
namespace Command {

// ── Single command execution ──────────────────────────────────────────────

void CommandInvoker::executeCommand(std::unique_ptr<ICommand> command) {
    command->execute();
    m_history.push(std::move(command));
}

void CommandInvoker::undoLastCommand() {
    if (m_history.empty()) {
        Utils::Logger::instance().warning(
            "Nothing to undo.", "CommandInvoker");
        return;
    }
    m_history.top()->undo();
    m_history.pop();
}

void CommandInvoker::undoAll() {
    while (!m_history.empty()) {
        m_history.top()->undo();
        m_history.pop();
    }
}

// ── Macro (batch) support ─────────────────────────────────────────────────

void CommandInvoker::addToQueue(std::unique_ptr<ICommand> command) {
    m_queue.push_back(std::move(command));
}

void CommandInvoker::executeQueue() {
    Utils::Logger::instance().info(
        "Executing macro batch of " + std::to_string(m_queue.size())
        + " commands.", "CommandInvoker");

    for (auto& cmd : m_queue) {
        cmd->execute();
        m_history.push(std::move(cmd));
    }
    m_queue.clear();
}

void CommandInvoker::clearQueue() {
    m_queue.clear();
}

std::size_t CommandInvoker::historySize() const {
    return m_history.size();
}

} // namespace Command
} // namespace SmartHome
