#pragma once
#include "macro.hpp"
#include "Client.hpp"
#include "Channel.hpp"
#include "ClientChannelHub.hpp"

#include <poll.h>
#include <map>
#include <vector>

class Model
{
private:
    std::map<ID, Client *> m_Client;
    std::map<ID, Channel *> m_Channel;

    std::map<ID, ClientChannelHub *> m_Hub;
    std::string m_password;

public:
    Model();
    ~Model();

    // Getters
    const std::string getModelInfo() const;

    std::vector<pollfd> getPollfds() const;
    // std::map<ID, Client *> getClients() const { return m_Client; }
    std::map<ID, ClientChannelHub *> getHub() const { return m_Hub; }
    Client *getClient(int t_fd) const;
    Client *getClient(const std::string &t_nick) const;
    Channel *getChannel(int t_id) const;
    Channel *getChannel(const std::string &t_name) const;
    int countClientsInChannel(const std::string &t_name) const;
    int getClientSize() const { return m_Client.size(); }
    int getChannelSize() const { return m_Channel.size(); }
    int getHubSize() const { return m_Hub.size(); }
    const std::string &getPassword() const { return m_password; }

    bool isClientOnChannel(int t_client_id, int t_channel_id) const;

    bool isNickNameInUse(const std::string &t_nickname) const;
    bool isChannelNameInUse(const std::string &t_channel_name) const;

    // Setters
    void setPassword(const std::string &t_password) { m_password = t_password; }

    // Add operations
    void addClient(int t_fd);
    void addChannel(const std::string &t_name);
    void addHub(int t_client_id, int t_channel_id, Role t_role);

    // Remove operations
    void removeClient(int t_fd);
    void removeChannel(int t_id);
    void removeHub(int t_client_id, int t_channel_id);
};
