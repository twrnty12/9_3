#pragma once 

#include <memory>
#include <string>
#include <vector>
#include <string>
#include "Observers.h"


class Observed {
public:
    void warning(const std::string& message);
    void error(const std::string& message);
    void fatal_error(const std::string& message);

    void AddObserver(std::weak_ptr<Observer> observer);
private:
    std::vector<std::weak_ptr<Observer>> observers_;
};