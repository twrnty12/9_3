#include "Observers.h"

void Warning::onWarning(const std::string& message) {
        log.print(message);
}   

void Error::onError(const std::string& message) {
        log.print(message);
}

void FatalError::onFatalError(const std::string& message) {
    log_c.print(message);
    log_f.print(message);
}

void FatalError::onFatalErrorExcept(const std::string& message) {
        throw (std::exception(message.c_str()));
}

void UnknownError::onUnknownError(const std::string& message) {
        throw (std::exception(message.c_str()));
}