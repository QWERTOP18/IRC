#pragma once
#include "config.hpp"
#include <iostream>
#include <string>

class Server
{
private:
    std::string m_password;
    int m_port;

    void setPort(const std::string &t_port);
    void setPassword(const std::string &t_password);

public:
    Server(const std::string &t_port, const std::string &t_password);
    ~Server();

    void start();
};

namespace Err
{
    namespace Port
    {

        static const char *NOT_NUMERIC = "Port must be a numeric value";
        static const char *OUT_OF_RANGE = "Port must be between 6660 and 6669";
    }
    namespace Password
    {
        static const char *TOO_SHORT = "Password must be at least 4 characters long";
        static const char *LOWERCASE_MISSING = "Password must include lowercase";
        static const char *UPPERCASE_MISSING = "Password must include uppercase";
    }
}
