#include "Model.hpp"

Model::Model()
{
    DEBUG_LOG(__func__);
}

Model::~Model()
{
    DEBUG_LOG(__func__);
    for (std::map<ID, Client *>::iterator it = m_Client.begin(); it != m_Client.end(); ++it)
    {
        delete it->second;
    }
    m_Client.clear();
    for (std::map<ID, Channel *>::iterator it = m_Channel.begin(); it != m_Channel.end(); ++it)
    {
        delete it->second;
    }
    m_Channel.clear();
    for (std::map<ID, ClientChannelHub *>::iterator it = m_Hub.begin(); it != m_Hub.end(); ++it)
    {
        delete it->second;
    }
    m_Hub.clear();
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

int Model::getChannelSize(const std::string &t_name) const
{
    DEBUG_LOG(__func__);
    int size = 0;
    ID id = id_hash(t_name);
    for (std::map<ID, ClientChannelHub *>::const_iterator it = m_Hub.begin(); it != m_Hub.end(); ++it)
    {
        if (it->second->getChannelId() == id)
            size++;
    }

    return size;
}
