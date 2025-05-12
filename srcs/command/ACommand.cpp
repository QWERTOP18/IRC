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

ResponseBody ACommand::start(int t_fd, const std::string &t_line)
{
    DEBUG_LOG();
    ResponseBody response;
    RequestBody request;

    if (m_Model->getClient(t_fd) == NULL)
    {
        response.m_status = ERR_NOSUCHNICK;
        return response;
    }
    request = parse(t_line);
    response = run(request);
    return response;
}

// ✨できればこのmethodはControllerに移動させたい
void ACommand::broadcast(const std::string &t_message, int t_channel_id)
{
    DEBUG_LOG();
    const std::map<int, ClientChannelHub *> &hub = m_Model->getHub();
    for (std::map<int, ClientChannelHub *>::const_iterator it = hub.begin(); it != hub.end(); ++it)
    {
        if (it->second->getChannelId() == t_channel_id)
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
