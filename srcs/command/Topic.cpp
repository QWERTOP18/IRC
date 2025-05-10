#include "Topic.hpp"
#include "../Model/Model.hpp"
//            ERR_NEEDMOREPARAMS              ERR_NOTONCHANNEL
//            RPL_NOTOPIC                     RPL_TOPIC
//            ERR_CHANOPRIVSNEEDED

Topic::Topic()
{
    DEBUG_LOG(__func__);
}
Topic::~Topic()
{
    DEBUG_LOG(__func__);
}

ResponseBody Topic::run(RequestBody t_request)
{
    DEBUG_LOG(__func__);
    ResponseBody response;
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
    if (m_Model->isClientOnChannel(t_request.m_fd, id_hash(t_request.m_channel)) == false)
    {
        response.m_status = ERR_NOTONCHANNEL;
        return response;
    }
    if (t_request.m_content.empty())
    {
        response.m_status = RPL_TOPIC;
        response.m_content = m_Model->getChannel(id_hash(t_request.m_channel))->getTopic();
    }
    else
    {
        m_Model->getChannel(id_hash(t_request.m_channel))->setTopic(t_request.m_content);
        response.m_status = RPL_TOPIC;
        response.m_content = t_request.m_content;
    }

    return response;
}
