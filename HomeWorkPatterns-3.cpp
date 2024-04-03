#pragma once 

#include <iostream>
#include "Observed.h"
#include "Log_message.h"

int main() {
    Observed od{};
    auto warning_ptr{std::make_shared<Warning>()};
    auto error_ptr{std::make_shared<Error>()};
    auto fatal_error_ptr{std::make_shared<FatalError>()};
    od.AddObserver(warning_ptr);
    od.AddObserver(error_ptr);
    od.AddObserver(fatal_error_ptr);

    od.warning("warning");
    od.error("error");
    od.fatal_error("fatal_error"); 

    FatalError f_e;
    LogMessage log_m(&f_e);
    try {
        log_m.error("Some error");
    }
    catch (std::exception& ex) {
        std::cout << ex.what();
    }
}