#include "Model.hpp"

Model::Model()
{
    DEBUG_LOG();
}

Model::~Model()
{
    DEBUG_LOG();
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
    DEBUG_LOG();
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

Client *Model::getClient(int t_fd) const
{
    std::map<ID, Client *>::const_iterator it = m_Client.find(t_fd);
    if (it != m_Client.end())
        return it->second;
    return NULL;
}

Client *Model::getClient(const std::string &t_nick) const
{
    for (std::map<ID, Client *>::const_iterator it = m_Client.begin(); it != m_Client.end(); ++it)
    {
        if (it->second->getNickname() == t_nick)
            return it->second;
    }
    return NULL;
}

Channel *Model::getChannel(int t_id) const
{
    std::map<ID, Channel *>::const_iterator it = m_Channel.find(t_id);
    if (it != m_Channel.end())
        return it->second;
    return NULL;
}

Channel *Model::getChannel(const std::string &t_name) const
{
    ID id = id_hash(t_name);
    for (std::map<ID, Channel *>::const_iterator it = m_Channel.begin(); it != m_Channel.end(); ++it)
    {
        if (it->second->getId() == id)
            return it->second;
    }
    return NULL;
}

int Model::getChannelSize(const std::string &t_name) const
{
    DEBUG_LOG();
    int size = 0;
    ID id = id_hash(t_name);
    for (std::map<ID, ClientChannelHub *>::const_iterator it = m_Hub.begin(); it != m_Hub.end(); ++it)
    {
        if (it->second->getChannelId() == id)
            size++;
    }
    return size;
}

bool Model::isClientOnChannel(int t_client_id, int t_channel_id) const
{
    DEBUG_LOG();
    for (std::map<ID, ClientChannelHub *>::const_iterator it = m_Hub.begin(); it != m_Hub.end(); ++it)
    {
        if (it->second->getClientId() == t_client_id && it->second->getChannelId() == t_channel_id)
            return true;
    }
    return false;
}

///
void Model::addClient(int t_fd)
{
    m_Client[t_fd] = new Client(t_fd);
}

void Model::addChannel(const std::string &t_name)
{
    Channel *ch = new Channel(t_name);
    m_Channel[ch->getId()] = ch;
}

void Model::addHub(int t_client_id, int t_channel_id, Role t_role)
{
    ClientChannelHub *hub = new ClientChannelHub(t_client_id, t_channel_id, t_role);
    m_Hub[hub->getId()] = hub;
}

void Model::removeClient(int t_fd)
{
    delete m_Client[t_fd];
    m_Client.erase(t_fd);

    for (std::map<ID, ClientChannelHub *>::iterator it = m_Hub.begin(); it != m_Hub.end();)
    {
        if (it->second->getClientId() == t_fd)
        {
            delete it->second;
            it = m_Hub.erase(it);
        }
        else
            ++it;
    }
    close(t_fd); // ✨test時に寡黙なエラーを吐きそうなので別の場所に持っていきたい
}

void Model::removeChannel(int t_id)
{
    delete m_Channel[t_id];
    m_Channel.erase(t_id);

    for (std::map<ID, ClientChannelHub *>::iterator it = m_Hub.begin(); it != m_Hub.end();)
    {
        if (it->second->getChannelId() == t_id)
        {
            delete it->second;
            it = m_Hub.erase(it);
        }
        else
            ++it;
    }
}

void Model::removeHub(int t_client_id, int t_channel_id)
{

    // 🚀hash2で高速に削除する
    for (std::map<ID, ClientChannelHub *>::iterator it = m_Hub.begin(); it != m_Hub.end();)
    {
        if (it->second->getClientId() == t_client_id && it->second->getChannelId() == t_channel_id)
        {
            delete it->second;
            it = m_Hub.erase(it);
        }
        else
            ++it;
    }
}

bool Model::isNickNameInUse(const std::string &t_nickname) const
{
    for (std::map<ID, Client *>::const_iterator it = m_Client.begin(); it != m_Client.end(); ++it)
    {
        if (it->second->getNickname() == t_nickname)
            return true;
    }
    return false;
}
bool Model::isChannelNameInUse(const std::string &t_channel_name) const
{
    for (std::map<ID, Channel *>::const_iterator it = m_Channel.begin(); it != m_Channel.end(); ++it)
    {
        if (it->second->getName() == t_channel_name)
            return true;
    }
    return false;
}
