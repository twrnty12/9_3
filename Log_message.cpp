#include "Log_message.h"

LogMessage::LogMessage(Observer* or_) {
    this->or = or_;
    type_name = typeid(*or).name();
}

Observer LogMessage::type() const {
    return *or;
}

const std::string LogMessage::message(const std::string& message) const {
    return (type_name + "\n" + message);
}

void LogMessage::error(const std::string& message) {
        if (dynamic_cast<Warning*>(or) != nullptr) {
        or->onWarning(this->message(message));
    }
    else if (dynamic_cast<Error*>(or) != nullptr) {
        or->onError(this->message(message));
    }
    else if (dynamic_cast<FatalError*>(or) != nullptr) {
        or->onFatalErrorExcept(this->message(message));
    }
    else if (dynamic_cast<UnknownError*>(or) != nullptr) {
        or->onUnknownError(this->message(message));
    }
}
