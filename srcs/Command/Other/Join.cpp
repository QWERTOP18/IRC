#include "Join.hpp"

Join::Join()
{
    DEBUG_FUNC();
}
Join::Join(Model *t_model) : ACommandBase(t_model)
{
    DEBUG_FUNC();
}
Join::~Join()
{
    DEBUG_FUNC();
}

RequestBody Join::parse(const std::string &t_line)
{
    DEBUG_FUNC();
    std::istringstream iss(t_line);
    RequestBody request;
    iss >> request.m_command;        // JOIN
    iss >> request.m_target_channel; // channel_name
    iss >> request.m_content;        // key
    if (request.m_target_channel.empty())
    {
        request.m_status = ERR_NEEDMOREPARAMS;
    }
    if (request.m_target_channel[0] != '#')
    {
        request.m_target_channel = "#" + request.m_target_channel;
    }
    return request;
}

ResponseBody Join::run(int t_fd, RequestBody t_request)
{
    DEBUG_FUNC();
    ResponseBody response;

    Channel *ch = m_Model->getChannel(t_request.m_target_channel);
    if (ch != NULL)
    {
        if (m_Model->isClientOnChannel(t_fd, ch->getId()))
        {
            if (m_Model->getRole(t_fd, ch->getId()) == INVITED)
            {
                m_Model->setRole(t_fd, ch->getId(), MEMBER);
                this->broadcast(t_fd, ch->getId(), "user joined");
                return ResponseBody(RPL_TOPIC, "You are now on channel " + t_request.m_target_channel);
            }
            return ResponseBody(ERR_USERONCHANNEL, "You are already on that channel");
        }

        // invited onlyの処理など
        if (ch->getMode().b_invite && m_Model->getRole(t_fd, ch->getId()) != INVITED)
        {
            return ResponseBody(ERR_INVITEONLYCHAN, "You are not invited to that channel");
        }
        if (ch->getMode().b_limit && m_Model->countClientsInChannel(ch->getName()) >= ch->getMode().b_limit)
        {
            return ResponseBody(ERR_CHANNELISFULL, "Channel is full");
        }

        if (!ch->getMode().b_key.empty() && ch->getMode().b_key != t_request.m_content)
        {
            return ResponseBody(ERR_BADCHANNELKEY, "Bad channel key");
        }

        m_Model->addHub(t_fd, ch->getId(), MEMBER);
        response.m_status = RPL_TOPIC;
        response.m_content = "You are now on channel " + t_request.m_target_channel;
        this->broadcast(t_fd, ch->getId(), "user joined");
        return response;
    }
    m_Model->addChannel(t_request.m_target_channel);
    ch = m_Model->getChannel(t_request.m_target_channel);

    LOG("channel created: " + t_request.m_target_channel);
    response.m_status = RPL_TOPIC; // ✨update
    response.m_content = "You are now on channel " + t_request.m_target_channel;

    m_Model->addHub(t_fd, ch->getId(), ADMIN);

    return response;
}
