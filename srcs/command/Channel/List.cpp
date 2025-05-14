#include "List.hpp"

List::List()
{
    DEBUG_FUNC();
}
List::List(Model *t_model) : ACommandBase(t_model)
{
    DEBUG_FUNC();
}
List::~List()
{
    DEBUG_FUNC();
}

ResponseBody List::run(int t_fd, RequestBody t_request)
{
    DEBUG_FUNC();
    ResponseBody response;
    Channel *channel = m_Model->getChannel(t_request.m_target_channel);
    if (channel == NULL)
    {
        return ResponseBody(ERR_NOSUCHCHANNEL, "No such channel");
    }
    response.m_status = RPL_LIST;
    response.m_content = to_string(m_Model->countClientsInChannel(t_request.m_target_channel));

    return response;
}

RequestBody List::parse(const std::string &t_line)
{
    DEBUG_FUNC();
    RequestBody request;
    std::istringstream iss(t_line);
    iss >> request.m_command; // LIST
    iss >> request.m_target_channel;

    if (request.m_target_channel.empty())
    {
        request.m_status = ERR_NEEDMOREPARAMS;
    }
    return request;
}
