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

void Server::setSocket()
{
    if ((m_sokcet = socket(AF_INET, SOCK_STREAM, 0))
     < 0)
        throw std::runtime_error(Err::Socket::OPEN_FAIL);

    int optval = 1;
    if (setsockopt(m_sokcet, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(m_sokcet)) < 0)
        throw std::runtime_error(Err::Socket::SETOPT_FAIL);

    if (fcntl(m_sokcet, F_SETFL, O_NONBLOCK) < 0)
        throw std::runtime_error(Err::Socket::NONBLOCK_FAIL);

    struct sockaddr_in server_addr = {};
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(m_port);
    if (bind(m_sokcet, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
        throw std::runtime_error(Err::Socket::BIND_FAIL);
    if (listen(m_sokcet, m_connect_max) < 0)
        throw std::runtime_error(Err::Socket::LISTEN_FAIL);
}
