#pragma once 

#include "Log_comand.h"
#include <fstream>

class LogFile : public LogCommand {
public:
    void print(const std::string& message) override;
    LogFile();
    ~LogFile() override;
private:
    std::ofstream f;
};