#include "Channel.hpp"

Channel::Channel(const std::string &name) : m_name(name),
                                            m_topic("")
{
    DEBUG_FUNC();
    m_id = id_hash(name);
    m_mode.b_invite = false;
    m_mode.b_topic = false;
    m_mode.b_key = "";
    m_mode.b_limit = 0;
}
Channel::~Channel()
{
    DEBUG_FUNC();
}
