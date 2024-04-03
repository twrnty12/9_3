#include "Log_file.h"

void LogFile::print(const std::string& message) {
    f << message << std::endl;
}

LogFile::LogFile() {
    f.open("log.txt", std::ios::app);
}

LogFile::~LogFile() {
    f.close();
}