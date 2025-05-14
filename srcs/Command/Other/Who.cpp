#include "Who.hpp"

Who::Who()
{
    DEBUG_FUNC();
}
Who::Who(Model *t_model) : ACommandBase(t_model)
{
    DEBUG_FUNC();
}
Who::~Who()
{
    DEBUG_FUNC();
}

ResponseBody Who::run(int t_fd, RequestBody t_request)
{
    DEBUG_FUNC();
    ResponseBody response;
    Client *target_client = m_Model->getClient(t_request.m_target_nickname);
    if (target_client == NULL)
    {
        response.m_status = RPL_ENDOFWHO;
        response.m_fd = t_fd; // ✨update prefix
        response.m_content = "List all users who match against   \"" + t_request.m_target_nickname + "\".";
        return response;
    }
    response.m_status = RPL_WHOREPLY;
    response.m_content = target_client->getClientInfo();

    return response;
}

RequestBody Who::parse(const std::string &t_line)
{
    DEBUG_FUNC();
    RequestBody request;
    std::istringstream iss(t_line);
    iss >> request.m_command;         // WHO
    iss >> request.m_target_nickname; // target_channel
    if (request.m_target_nickname.empty())
    {
        request.m_status = ERR_NEEDMOREPARAMS;
    }
    return request;
}
