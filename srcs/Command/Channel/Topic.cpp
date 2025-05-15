#include "Topic.hpp"

Topic::Topic()
{
    DEBUG_FUNC();
}
Topic::Topic(Model *t_model) : ACommandBase(t_model)
{
    DEBUG_FUNC();
}
Topic::~Topic()
{
    DEBUG_FUNC();
}

RequestBody Topic::parse(const std::string &t_line)
{
    DEBUG_FUNC();
    std::istringstream iss(t_line);
    RequestBody request;
    iss >> request.m_command;        // Topic
    iss >> request.m_target_channel; // channel_name
    iss >> request.m_content;        // topic

    if (request.m_target_channel.empty())
    {
        request.m_status = ERR_NEEDMOREPARAMS;
    }
    return request;
}

ResponseBody Topic::run(int t_fd, RequestBody t_request)
{
    DEBUG_FUNC();
    ResponseBody response;
    response.m_command = "TOPIC";

    Channel *ch = m_Model->getChannel(t_request.m_target_channel);
    if (ch == NULL)
    {
        response.m_status = ERR_NOSUCHCHANNEL;
        return response;
    }
    if (!m_Model->isClientOnChannel(t_fd, ch->getId()))
    {
        response.m_status = ERR_NOTONCHANNEL;
        return response;
    }

    if (t_request.m_content.empty())
    {
        response.m_status = RPL_TOPIC;
        response.m_content = ch->getTopic();
        if (response.m_content.empty())
        {
            response.m_status = RPL_NOTOPIC;
            response.m_content = "No topic is set";
        }
    }
    else
    {
        ch->setTopic(t_request.m_content);
        response.m_status = RPL_TOPIC;
        response.m_content = "Topic set to " + t_request.m_content;

        this->broadcast(t_fd, ch->getId(), "topic changed");
        LOG("topic changed: " + t_request.m_content);
    }

    return response;
}
