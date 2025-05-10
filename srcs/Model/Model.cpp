#include "Model.hpp"

Model::Model()
{
    DEBUG_LOG(__func__);
}

Model::~Model()
{
    DEBUG_LOG(__func__);
    // for (auto &client : m_Client)
    //     delete client.second;
    // for (auto &channel : m_Channel)
    //     delete channel.second;
    // for (auto &hub : m_Hub)
    //     delete hub.second;
}

std::vector<pollfd> Model::getPollfds() const
{
    DEBUG_LOG(__func__);
    std::vector<pollfd> pollfds;
    for (std::map<ID, Client *>::const_iterator client = m_Client.begin(); client != m_Client.end(); ++client)
    {
        pollfd pfd;
        pfd.fd = client->first;
        pfd.events = POLLIN;
        pfd.revents = 0;
        pollfds.push_back(pfd);
    }
    return pollfds;
}
