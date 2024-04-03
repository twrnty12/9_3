#pragma once

#include "Log_comand.h"
#include <iostream>

class LogConsole : public LogCommand {
public:
    void print(const std::string& message) override;
};