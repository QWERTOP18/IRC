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
    iss >> request.m_content;        // limit

    if (request.m_target_channel.empty() || request.m_content.empty())
    {
        request.m_status = ERR_NEEDMOREPARAMS;
    }
    return request;
}

ResponseBody Mode::run(int t_fd, RequestBody t_request)
{
    DEBUG_FUNC();
    ResponseBody response;
    response.m_command = "Mode";
    if (t_request.m_target_channel.empty() || t_request.m_content.empty())
    {
        response.m_status = ERR_NEEDMOREPARAMS;
        response.m_content = "Not enough parameters";
        return response;
    }

    Channel *ch = m_Model->getChannel(t_request.m_target_channel);
    if (ch == NULL)
    {
        response.m_status = ERR_NOSUCHCHANNEL;
        response.m_content = "No such channel";
        return response;
    }

    // 権限の確認
    // if (!m_Model->isClientOnChannel(t_fd, ch->getId()))
    // {
    //     return response;
    // }

    this->broadcast(t_fd, ch->getId(), "Mode changed");
    return response;
}
