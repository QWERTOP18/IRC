#include "Client.hpp"

Client::Client(int fd) : m_fd(fd)
{
    DEBUG_LOG();
}
Client::~Client()
{
    DEBUG_LOG();
}
