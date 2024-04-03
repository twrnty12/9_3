#pragma once

#include <string>
#include "Observers.h"

class LogMessage {
public:
    LogMessage(Observer* or_);
    Observer type() const;
    const std::string message(const std::string& message) const;
    void error(const std::string& message);
    
private:
    Observer* or;
    std::string type_name{};
};