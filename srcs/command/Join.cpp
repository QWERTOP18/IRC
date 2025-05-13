#include "Join.hpp"
#include "../Model/Model.hpp"

Join::Join()
{
    DEBUG_LOG();
}
Join::Join(Model *t_model) : ACommandBase(t_model)
{
    DEBUG_LOG();
}
Join::~Join()
{
    DEBUG_LOG();
}

RequestBody Join::parse(const std::string &t_line)
{
    DEBUG_LOG();
    std::istringstream iss(t_line);
    RequestBody request;
    iss >> request.m_command;        // JOIN
    iss >> request.m_target_channel; // channel_name
    iss >> request.m_content;        // key
    return request;
}

ResponseBody Join::run(int t_fd, RequestBody t_request)
{
    DEBUG_LOG();
    ResponseBody response;
    response.m_command = "JOIN";

    Channel *ch = m_Model->getChannel(t_request.m_target_channel);
    if (ch != NULL)
    {
        if (m_Model->isClientOnChannel(t_fd, ch->getId()))
        {
            response.m_status = RPL_TOPIC;
            response.m_content = "You are already on that channel";
            return response;
        }

        m_Model->addHub(t_request.m_fd, ch->getId(), MEMBER);
        response.m_status = RPL_TOPIC;
        response.m_content = "You are now on channel " + t_request.m_target_channel;
        this->broadcast(t_fd, ch->getId(), "user joined");
        return response;
    }
    m_Model->addChannel(t_request.m_target_channel);
    this->broadcast(t_fd, m_Model->getChannel(t_request.m_target_channel)->getId(), "user joined");
    LOG("channel created: " + t_request.m_target_channel);
    response.m_status = RPL_TOPIC; // ✨update
    response.m_content = "You are now on channel " + t_request.m_target_channel;

    m_Model->addHub(t_request.m_fd, m_Model->getChannel(t_request.m_target_channel)->getId(), ADMIN);

    return response;
}
