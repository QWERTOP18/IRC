#include "Client.hpp"

Client::Client(int fd) : m_fd(fd), m_status(DISCONNECTED)
{
    DEBUG_LOG();
    m_buf_read.clear();
}

Client::~Client()
{
    DEBUG_LOG();
}
