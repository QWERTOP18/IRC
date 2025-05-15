#include "Part.hpp"

Part::Part()
{
    DEBUG_FUNC();
}
Part::Part(Model *t_model) : ACommandBase(t_model)
{
    DEBUG_FUNC();
}
Part::~Part()
{
    DEBUG_FUNC();
}

RequestBody Part::parse(const std::string &t_line)
{
    DEBUG_FUNC();
    std::istringstream iss(t_line);
    RequestBody request;
    iss >> request.m_command;        // Part
    iss >> request.m_target_channel; // channel_name
    iss >> request.m_content;        // message

    if (request.m_target_channel.empty())
    {
        request.m_status = ERR_NEEDMOREPARAMS;
    }
    return request;
}

ResponseBody Part::run(int t_fd, RequestBody t_request)
{
    DEBUG_FUNC();
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

    this->broadcast(t_fd, ch->getId(), "user left");
    m_Model->removeHub(t_fd, ch->getId());
    response.m_status = RPL_TOPIC;
    response.m_content = "You have left " + t_request.m_target_channel;

    LOG("user left channel: " + t_request.m_target_channel);

    return response;
}
