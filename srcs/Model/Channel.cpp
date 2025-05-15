#include "Channel.hpp"

Channel::Channel(const std::string &name) : m_name(name),
                                            m_topic(""),
                                            m_key(""),
                                            m_limit(0)
{
    DEBUG_FUNC();
    m_id = id_hash(name);
    m_mode.b_invite = false;
    m_mode.b_topic = false;
    m_mode.b_key = false;
    m_mode.b_limit = false;
}
Channel::~Channel()
{
    DEBUG_FUNC();
}
