#pragma once
#include "macro.hpp"
#include "Client.hpp"
#include "Channel.hpp"

class ClientChannelHub
{
private:
    ID m_id;
    ID m_client_id;
    ID m_channel_id;
    Role m_role;

public:
    ClientChannelHub(ID client_id, ID channel_id, Role role);
    ~ClientChannelHub();

    ID getId() const { return m_id; }
    ID getClientId() const { return m_client_id; }
    ID getChannelId() const { return m_channel_id; }
    Role getRole() const { return m_role; }
    void setRole(Role role) { m_role = role; }
};
