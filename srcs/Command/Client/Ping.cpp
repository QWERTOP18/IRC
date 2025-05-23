#include "Ping.hpp"

Ping::Ping()
{
    DEBUG_FUNC();
}
Ping::Ping(Model *t_model) : ACommandBase(t_model)
{
    DEBUG_FUNC();
}
Ping::~Ping()
{
    DEBUG_FUNC();
}

ResponseBody Ping::run(int t_fd, RequestBody t_request)
{
    DEBUG_FUNC();
    Client *client = m_Model->getClient(t_fd);

    return ResponseBody(RPL_NONE, "PONG", t_request.m_content);
}

RequestBody Ping::parse(const std::string &t_line)
{
    DEBUG_FUNC();
    RequestBody request;
    std::istringstream iss(t_line);
    iss >> request.m_command; // Ping
    iss >> request.m_content;
    if (request.m_content.empty())
    {
        request.m_status = ERR_NEEDMOREPARAMS;
    }

    return request;
}
