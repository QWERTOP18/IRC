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
    const Client *getClient(int fd) const
    {
        std::map<ID, Client *>::const_iterator it = m_Client.find(fd);
        if (it != m_Client.end())
            return it->second;
        return NULL;
    }

    void addClient(int fd)
    {
        m_Client[fd] = new Client(fd);
    }
    void addChannel(int fd)
    {
        m_Channel[fd] = new Channel();
    }
    void addHub(int fd)
    {
        m_Hub[fd] = new ClientChannelHub();
    }
    void manageClientRequest(int fd)
    {

        ACommand *command = getClient(fd)->parseRequest();
        if (command)
        {
            command->execute();
            delete command;
        }
        else
        {
            LOG("Invalid command");
        }
    }

    void removeClient(int fd)
    {
        delete m_Client[fd];
        m_Client.erase(fd);
    }
};
