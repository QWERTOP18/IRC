#include "Channel.hpp"

Channel::Channel(const std::string &name) : m_name(name)
{
    DEBUG_LOG(__func__);
    m_id = id_hash(name);
}
Channel::~Channel()
{
    DEBUG_LOG(__func__);
}
