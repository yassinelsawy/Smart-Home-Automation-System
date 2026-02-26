#include "ICommand.h"   

using namespace std;

void ICommand::execute() {
    // Default implementation (can be overridden by derived classes)
}

void ICommand::undo() {
    // Default implementation (can be overridden by derived classes)
}

ICommand::~ICommand() {
    // Virtual destructor to ensure proper cleanup of derived classes
}