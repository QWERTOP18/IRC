#include "PrivMsg.hpp"

PrivMsg::PrivMsg()
{
    DEBUG_FUNC();
}

PrivMsg::PrivMsg(Model *t_model) : ACommandBase(t_model)
{
    DEBUG_FUNC();
}

PrivMsg::~PrivMsg()
{
    DEBUG_FUNC();
}

RequestBody PrivMsg::parse(const std::string &t_line)
{
    DEBUG_FUNC();
    std::istringstream iss(t_line);
    RequestBody request;
    iss >> request.m_command;         // PrivMsg
    iss >> request.m_target_nickname; // nick_name
    if (request.m_target_nickname[0] == '#')
    {
        request.m_target_channel = request.m_target_nickname.substr(1);
    }
    iss >> request.m_content; // message
    if (request.m_target_nickname.empty() || request.m_content.empty())
    {
        request.m_status = ERR_NEEDMOREPARAMS;
    }
    return request;
}

ResponseBody PrivMsg::run(int t_fd, RequestBody t_request)
{
    DEBUG_FUNC();
    ResponseBody response;
    response.m_command = "PRIVMSG";

    if (!t_request.m_target_channel.empty())
    {
        Channel *ch = m_Model->getChannel(t_request.m_target_channel);
        if (ch == NULL)
        {
            return ResponseBody(ERR_NOSUCHCHANNEL, "No such channel");
        }
        if (!m_Model->isClientOnChannel(t_fd, ch->getId()))
        {
            return ResponseBody(ERR_NOTONCHANNEL, "You're not on that channel");
        }
        this->broadcast(t_fd, ch->getId(), t_request.m_content);
    }
    else
    {
        Client *target_client = m_Model->getClient(t_request.m_target_nickname);
        if (target_client == NULL)
        {
            return ResponseBody(ERR_NOSUCHNICK, "No such nick");
        }

        this->sendToClient(t_fd, target_client->getFd(), t_request.m_content);
    }

    response.m_status = NO_REPLY;

    return response;
}
