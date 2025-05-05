#include "Server.hpp"

void Server::setPort(const std::string &t_port)
{
    for (size_t i = 0; i < t_port.length(); ++i)
    {
        if (!std::isdigit(t_port[i]))
        {
            throw std::invalid_argument(Err::Port::NOT_NUMERIC);
        }
    }

    std::istringstream iss(t_port);
    int port;
    iss >> port;

    if (iss.fail() || !iss.eof())
    {
        throw std::invalid_argument(Err::Port::NOT_NUMERIC);
    }

    if (port < 6660 || port > 6669)
    {
        throw std::invalid_argument(Err::Port::OUT_OF_RANGE);
    }

    m_port = port;
}

void Server::setPassword(const std::string &t_password)
{
    if (t_password.length() < 4)
    {
        throw std::invalid_argument(Err::Password::TOO_SHORT);
    }

    bool hasLower = false;
    bool hasUpper = false;

    for (size_t i = 0; i < t_password.length(); ++i)
    {
        if (std::islower(t_password[i]))
        {
            hasLower = true;
        }
        if (std::isupper(t_password[i]))
        {
            hasUpper = true;
        }
    }

    if (!hasLower)
    {
        throw std::invalid_argument(Err::Password::LOWERCASE_MISSING);
    }

    if (!hasUpper)
    {
        throw std::invalid_argument(Err::Password::UPPERCASE_MISSING);
    }

    m_password = t_password;
}