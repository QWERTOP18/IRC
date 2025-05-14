#include "Channel.hpp"

Channel::Channel(const std::string &name) : m_name(name)
{
    DEBUG_FUNC();
    m_id = id_hash(name);
}
Channel::~Channel()
{
    DEBUG_FUNC();
}
