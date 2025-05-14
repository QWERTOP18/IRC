#include "Client.hpp"

Client::Client(int fd) : m_fd(fd), m_status(DISCONNECTED)
{
    DEBUG_FUNC();
    m_buf_read.clear();
}

Client::~Client()
{
    DEBUG_FUNC();
}
