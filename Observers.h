#pragma once 

#include <string>
#include "Log_console.h"
#include "Log_file.h"

class Observer {
public:
    virtual void onWarning(const std::string& message) {}
    virtual void onError(const std::string& message) {}
    virtual void onFatalError(const std::string& message) {}
    virtual void onUnknownError(const std::string& message) {}
    virtual void onFatalErrorExcept(const std::string& message) {}
};

class Warning : public Observer {
public:
    void onWarning(const std::string& message) override;
private:
    LogConsole log{};
};

class Error : public Observer {
public: 
    void onError(const std::string& message) override;
private:
    LogFile log{};
};

class FatalError : public Observer {
public: 
    void onFatalError(const std::string& message) override;
    void onFatalErrorExcept(const std::string& message) override;
private:
    LogConsole log_c{};
    LogFile log_f{};
};

class UnknownError : public Observer {
    void onUnknownError(const std::string& message) override;
};