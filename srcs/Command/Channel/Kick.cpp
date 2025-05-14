#include "Kick.hpp"

Kick::Kick()
{
    DEBUG_FUNC();
}
Kick::Kick(Model *t_model) : ACommandBase(t_model)
{
    DEBUG_FUNC();
}
Kick::~Kick()
{
    DEBUG_FUNC();
}

RequestBody Kick::parse(const std::string &t_line)
{
    DEBUG_FUNC();
    std::istringstream iss(t_line);
    RequestBody request;
    iss >> request.m_command;        // KICK
    iss >> request.m_target_channel; // channel_name
    iss >> request.m_target_nickname;
    iss >> request.m_content; // reason

    if (request.m_target_nickname.empty() || request.m_target_channel.empty())
    {
        request.m_status = ERR_NEEDMOREPARAMS;
    }
    return request;
}

ResponseBody Kick::run(int t_fd, RequestBody t_request)
{
    DEBUG_FUNC();
    ResponseBody response;
    response.m_command = "Kick";

    Client *target = m_Model->getClient(t_request.m_target_nickname);
    Channel *ch = m_Model->getChannel(t_request.m_target_channel);

    if (target == NULL)
    {
        response.m_status = ERR_NOSUCHNICK;
        response.m_content = "No such nickname";
        return response;
    }
    if (ch == NULL)
    {
        response.m_status = ERR_NOSUCHCHANNEL;
        response.m_content = "No such channel";
        return response;
    }
    if (m_Model->isClientOnChannel(t_fd, ch->getId()))
    {
        response.m_status = RPL_TOPIC;
        response.m_content = "You are already on that channel";
        return response;
    }

    // m_Model->addHub(t_request.m_fd, ch->getId(), );
    response.m_status = RPL_TOPIC;
    response.m_content = "You have been Kickd to " + t_request.m_target_channel;
    this->broadcast(t_fd, ch->getId(), "user Kickd");
    return response;
}
