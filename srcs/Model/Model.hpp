#pragma once
#include "macro.hpp"
#include "Client.hpp"
#include "Channel.hpp"
#include "ClientChannelHub.hpp"

#include <poll.h>
#include <map>
#include <vector>
using std::vector;

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
    void handleCommand(int fd)
    {
        // Handle command from client
        // This is a placeholder for the actual command handling logic
        std::cout << "Handling command from client with fd: " << fd << std::endl;
    }
    void removeClient(int fd)
    {
        delete m_Client[fd];
        m_Client.erase(fd);
    }
};
