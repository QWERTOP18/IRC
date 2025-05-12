#include "ACommand.hpp"
#include "../Model/Model.hpp"

ACommand::ACommand()
{
    DEBUG_LOG();
}
ACommand::ACommand(Model *t_model) : m_Model(t_model)
{
    DEBUG_LOG();
}

ACommand::~ACommand()
{
    DEBUG_LOG();
}

// ✨できればこのmethodはControllerに移動させたい
void ACommand::broadcast(int fd, const std::string &t_message, int t_channel_id)
{
    DEBUG_LOG();
    const std::map<int, ClientChannelHub *> &hub = m_Model->getHub();
    for (std::map<int, ClientChannelHub *>::const_iterator it = hub.begin(); it != hub.end(); ++it)
    {
        if (it->second->getChannelId() == t_channel_id && it->first != fd)
        {
            sendToClient(it->first, t_message);
        }
    }
}

// ✨できればこのmethodはControllerに移動させたい
void ACommand::sendToClient(int fd, const std::string &t_message)
{
    DEBUG_LOG();
    if (fd < 0)
        return;
    send(fd, t_message.c_str(), strlen(t_message.c_str()), 0);
}
