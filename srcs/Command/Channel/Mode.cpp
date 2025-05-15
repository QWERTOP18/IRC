#include "Mode.hpp"

Mode::Mode()
{
    DEBUG_FUNC();
}
Mode::Mode(Model *t_model) : ACommandBase(t_model)
{
    DEBUG_FUNC();
}
Mode::~Mode()
{
    DEBUG_FUNC();
}

RequestBody Mode::parse(const std::string &t_line)
{
    DEBUG_FUNC();
    std::istringstream iss(t_line);
    RequestBody request;
    iss >> request.m_command;        // Mode
    iss >> request.m_target_channel; // channel_name
    iss >> request.m_content;        // + or -　char
    iss >> request.m_content2;       // limit or key or user

    if (request.m_target_channel.empty() || request.m_content.empty())
    {
        request.m_status = ERR_NEEDMOREPARAMS;
    }
    if (request.m_content[0] != '+' && request.m_content[0] != '-')
    {
        request.m_status = ERR_UNKNOWNMODE;
    }
    if (request.m_content[1] != 'i' && request.m_content[1] != 't' && request.m_content[1] != 'l' && request.m_content[1] != 'k' && request.m_content[1] != 'o')
    {
        request.m_status = ERR_UNKNOWNMODE;
    }
    if (request.m_content[1] == 'l' || request.m_content[1] == 'k' || request.m_content[1] == 'o')
    {
        if (request.m_content2.empty())
        {
            request.m_status = ERR_NEEDMOREPARAMS;
        }
    }

    return request;
}

ResponseBody Mode::run(int t_fd, RequestBody t_request)
{
    DEBUG_FUNC();
    ResponseBody response;
    response.m_command = "Mode";

    Channel *ch = m_Model->getChannel(t_request.m_target_channel);

    bool b = (t_request.m_content[0] == '+') ? true : false;

    if (t_request.m_content[1] == 'i')
    {
        ch->setInvite(b);
    }
    else if (t_request.m_content[1] == 't')
    {
        ch->setTopic(b);
    }
    else if (t_request.m_content[1] == 'l')
    {
        if (b)
        {

            int limit = atoi(t_request.m_content2.c_str());
            if (limit < m_Model->countClientsInChannel(ch->getName()))
            {
                return ResponseBody(ERR_CHANNELISFULL, "Channel is full");
            }
            ch->setLimit(limit);
        }
        else
        {
            ch->setLimit(0);
        }
    }
    else if (t_request.m_content[1] == 'k')
    {
        if (b)
        {
            ch->setKey(t_request.m_content2);
        }
        else
        {
            ch->setKey("");
        }
    }
    else if (t_request.m_content[1] == 'o')
    {
        Client *target = m_Model->getClient(t_request.m_content2);
        if (target == NULL)
        {
            return ResponseBody(ERR_NOSUCHNICK, "No such nickname");
        }
        if (!m_Model->isClientOnChannel(target->getFd(), ch->getId()))
        {
            return ResponseBody(ERR_NOTONCHANNEL, "is not on channel");
        }
        m_Model->setRole(target->getFd(), ch->getId(), b ? ADMIN : MEMBER);
        if (b)
        {
            response.m_content = target->getNickname() + " is now a channel operator";
        }
        else
        {
            response.m_content = target->getNickname() + " is no longer a channel operator";
        }
    }
    this->broadcast(t_fd, ch->getId(), "mode changed");
    response.m_status = RPL_TOPIC;
    response.m_content = "Mode changed to " + t_request.m_content;
    LOG("mode changed: " + t_request.m_content);
    return response;
}
