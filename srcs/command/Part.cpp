#include "Part.hpp"
#include "../Model/Model.hpp"

Part::Part()
{
    DEBUG_LOG();
}
Part::Part(Model *t_model) : ACommandBase(t_model)
{
    DEBUG_LOG();
}
Part::~Part()
{
    DEBUG_LOG();
}

RequestBody Part::parse(const std::string &t_line)
{
    DEBUG_LOG();
    std::istringstream iss(t_line);
    RequestBody request;
    iss >> request.m_command;        // Part
    iss >> request.m_target_channel; // channel_name
    iss >> request.m_content;        // message
    return request;
}

ResponseBody Part::run(int t_fd, RequestBody t_request)
{
    DEBUG_LOG();
    ResponseBody response;
    response.m_command = "PART";

    Channel *ch = m_Model->getChannel(t_request.m_target_channel);
    if (ch == NULL)
    {
        response.m_status = ERR_NOSUCHCHANNEL;
        response.m_content = "No such channel";
        return response;
    }
    if (!m_Model->isClientOnChannel(t_fd, ch->getId()))
    {
        response.m_status = ERR_NOTONCHANNEL;
        response.m_content = "You're not on that channel";
        return response;
    }

    m_Model->removeHub(t_fd, ch->getId());
    response.m_status = RPL_TOPIC;
    // response.m_content = "No topic is set";
    this->broadcast(t_fd, ch->getId(), "user left");
    LOG("user left channel: " + t_request.m_target_channel);

    return response;
}
