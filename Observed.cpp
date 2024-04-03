#include "Observed.h"

void Observed::warning(const std::string& message) {
    for (auto observer : observers_) {
        if (auto strong_ptr = observer.lock()) {
            strong_ptr->onWarning(message);
        }
    }
}

void Observed::error(const std::string& message) {
    for (auto observer : observers_) {
        if (auto strong_ptr = observer.lock()) {
            strong_ptr->onError(message);
        }
    }
}

void Observed::fatal_error(const std::string& message) {
        for (auto observer : observers_) {
        if (auto strong_ptr = observer.lock()) {
            strong_ptr->onFatalError(message);
        }
    }
}

void Observed::AddObserver(std::weak_ptr<Observer> observer) {
    observers_.push_back(observer);
}