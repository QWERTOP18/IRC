#pragma once
#include "config.hpp"
#include <iostream>
#include <string>

class Server
{
private:
    const std::string m_password;
    int m_port;

public:
    Server(const std::string &t_port, const std::string &t_password);
    ~Server();

    void start();
};
