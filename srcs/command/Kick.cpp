#include "Kick.hpp"
#include "../Model/Model.hpp"

Kick::Kick()
{
    DEBUG_LOG();
}
Kick::~Kick()
{
    DEBUG_LOG();
}
// Numeric Replies:

//            ERR_NEEDMOREPARAMS              ERR_NOSUCHCHANNEL
//            ERR_BADCHANMASK                 ERR_CHANOPRIVSNEEDED
//            ERR_NOTONCHANNEL

ResponseBody Kick::start()
{
    DEBUG_LOG();
    ResponseBody response;
    response.m_command = "KICK";
    if (m_request.m_channel.empty())
    {
        response.m_status = ERR_NEEDMOREPARAMS;
        return response;
    }
    if (m_Model->getChannel(id_hash(m_request.m_channel)) == NULL)
    {
        response.m_status = ERR_NOSUCHCHANNEL;
        return response;
    }
    if (m_Model->isClientOnChannel(m_request.m_fd, id_hash(m_request.m_channel)) == false)
    {
        response.m_status = ERR_NOTONCHANNEL;
        return response;
    }
    // if (m_Model->getChannel(id_hash(m_request.m_channel))->getMode() == true)
    // {
    //     response.m_status = ERR_CHANOPRIVSNEEDED;
    //     return response;
    // }

    m_Model->removeHub(m_request.m_fd, id_hash(m_request.m_channel));
    return response;
}
