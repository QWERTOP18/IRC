#include "Channel.hpp"

Channel::Channel(const std::string &name) : m_name(name)
{
    DEBUG_LOG();
    m_id = id_hash(name);
}
Channel::~Channel()
{
    DEBUG_LOG();
}
