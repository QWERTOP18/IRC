#include "Client.hpp"

Client::Client(int fd) : m_fd(fd)
{
    DEBUG_LOG(__func__);
}
Client::~Client()
{
    DEBUG_LOG(__func__);
}
