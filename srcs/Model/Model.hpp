#pragma once
#include "macro.hpp"
#include "Client.hpp"
#include "Channel.hpp"
#include "ClientChannelHub.hpp"
#include "../Command/ACommand.hpp"

#include <poll.h>
#include <map>
#include <vector>

class Model
{
private:
    std::map<ID, Client *> m_Client;
    std::map<ID, Channel *> m_Channel;
    std::map<ID, ClientChannelHub *> m_Hub;

public:
    Model();
    ~Model();
    std::vector<pollfd> getPollfds() const;
    const Client *getClient(int t_fd) const
    {
        std::map<ID, Client *>::const_iterator it = m_Client.find(t_fd);
        if (it != m_Client.end())
            return it->second;
        return NULL;
    }
    int getChannelSize(const std::string &t_name) const;

    void addClient(int t_fd)
    {
        m_Client[t_fd] = new Client(t_fd);
    }
    void addChannel(const std::string &t_name)
    {
        Channel *ch = new Channel(t_name);
        m_Channel[ch->getId()] = ch;
    }

    void addHub(int t_client_id, int t_channel_id, Role t_role)
    {
        ClientChannelHub *hub = new ClientChannelHub(t_client_id, t_channel_id, t_role);
        m_Hub[hub->getId()] = hub;
    }

    void removeClient(int t_fd)
    {
        delete m_Client[t_fd];
        m_Client.erase(t_fd);
    }
};
