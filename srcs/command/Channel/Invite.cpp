#include "Invite.hpp"

Invite::Invite()
{
    DEBUG_FUNC();
}
Invite::Invite(Model *t_model) : ACommandBase(t_model)
{
    DEBUG_FUNC();
}
Invite::~Invite()
{
    DEBUG_FUNC();
}

RequestBody Invite::parse(const std::string &t_line)
{
    DEBUG_FUNC();
    std::istringstream iss(t_line);
    RequestBody request;
    iss >> request.m_command;        // JOIN
    iss >> request.m_target_channel; // channel_name
    iss >> request.m_target_nickname;
    if (request.m_target_nickname.empty() || request.m_target_channel.empty())
    {
        request.m_status = ERR_NEEDMOREPARAMS;
    }
    return request;
}

ResponseBody Invite::run(int t_fd, RequestBody t_request)
{
    DEBUG_FUNC();
    ResponseBody response;
    response.m_command = "INVITE";

    Client *target = m_Model->getClient(t_request.m_target_nickname);
    Channel *ch = m_Model->getChannel(t_request.m_target_channel);

    if (target == NULL)
    {
        return ResponseBody(ERR_NOSUCHNICK, "No such nickname");
    }
    if (ch == NULL)
    {
        return ResponseBody(ERR_NOSUCHCHANNEL, "No such channel");
    }
    if (m_Model->isClientOnChannel(target->getFd(), ch->getId()))
    {
        return ResponseBody(ERR_USERONCHANNEL, "is already on channel");
    }

    m_Model->addHub(t_request.m_fd, ch->getId(), INVITED);
    response.m_status = RPL_TOPIC;
    response.m_content = "You have been invited to " + t_request.m_target_channel;
    this->broadcast(t_fd, ch->getId(), "user invited");
    return response;
}
