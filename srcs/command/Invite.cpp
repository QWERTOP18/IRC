#include "Invite.hpp"

#include "../Model/Model.hpp"

Invite::Invite()
{
    DEBUG_LOG(__func__);
}
Invite::~Invite()
{
    DEBUG_LOG(__func__);
}

ResponseBody Invite::run(RequestBody t_request)
{
    DEBUG_LOG(__func__);
    ResponseBody response;
    if (m_Model->getClient(t_request.m_fd) == NULL)
    {
        response.m_status = ERR_NOSUCHNICK;
        return response;
    }

    if (t_request.m_channel.empty())
    {
        response.m_status = ERR_NEEDMOREPARAMS;
        return response;
    }
    if (m_Model->getChannel(id_hash(t_request.m_channel)) == NULL)
    {
        response.m_status = ERR_NOSUCHCHANNEL;

        return response;
    }
    {
        response.m_status = 401;
        return response;
    }

    if (m_Model->getClient(t_request.m_fd)->getStatus() < AUTHENTICATED)
    {
        response.m_status = 451;
        return response;
    }
    // if (m_Model->getClient(t_request.m_fd)->isOperator(channel_name) == false)
    // {
    //     response.m_status = 482;
    //     return response;
    // }

    // if (m_Model->getClient(target_nick)->isInChannel(channel_name))
    // {
    //     response.m_status = 443;
    //     return response;
    // 443     ERR_USERONCHANNEL
    //                     "<user> <channel> :is already on channel"

    //             - Returned when a client tries to invite a user to a
    //               channel they are already on.
    // }

    m_Model->addHub(m_Model->getClient(t_request.m_fd)->getFd(), id_hash(t_request.m_channel), INVITED);
    return response;
}
