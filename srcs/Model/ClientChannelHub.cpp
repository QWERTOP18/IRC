#include "ClientChannelHub.hpp"
ClientChannelHub::ClientChannelHub(ID client_id, ID channel_id, Role role)
    : m_client_id(client_id), m_channel_id(channel_id), m_role(role)
{
    DEBUG_LOG(__func__);
    m_id = id_hash2(m_client_id, m_channel_id);
}

ClientChannelHub::~ClientChannelHub()
{
}
