#include "ACommandBase.hpp"
#include "../Model/Model.hpp"

ACommandBase::ACommandBase()
{
    DEBUG_LOG();
}
ACommandBase::ACommandBase(Model *t_model) : m_Model(t_model)
{
    DEBUG_LOG();
}

ACommandBase::~ACommandBase()
{
    DEBUG_LOG();
}

void ACommandBase::broadcast(int t_fd, int t_channel_id, const std::string &t_message)
{
    DEBUG_LOG();
    const std::map<int, ClientChannelHub *> &hub = m_Model->getHub();
    for (std::map<int, ClientChannelHub *>::const_iterator it = hub.begin(); it != hub.end(); ++it)
    {
        if (it->second->getChannelId() == t_channel_id && it->second->getClientId() != t_fd)
        {
            sendToClient(t_fd, it->first, t_message);
        }
    }
}

void ACommandBase::sendToClient(int t_fd, int t_target_fd, const std::string &t_message)
{
    DEBUG_LOG();

    std::string message = ":" + m_Model->getClient(t_fd)->getClientInfo() + " " + t_message + "\r\n";
    send(t_target_fd, message.c_str(), strlen(message.c_str()), 0);
}
