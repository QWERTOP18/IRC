#include "Pass.hpp"

Pass::Pass()
{
    DEBUG_FUNC();
}
Pass::Pass(Model *t_model) : ACommandBase(t_model)
{
    DEBUG_FUNC();
}
Pass::~Pass()
{
    DEBUG_FUNC();
}
ResponseBody Pass::run(int t_fd, RequestBody t_request)
{
    DEBUG_FUNC();
    ResponseBody response;
    if (t_request.m_content.empty())
    {
        response.m_status = ERR_NEEDMOREPARAMS;
        response.m_content = "Not enough parameters";
        return response;
    }
    Client *client = m_Model->getClient(t_fd);

    if (client->getStatus() > CONNECTED1)
    {
        response.m_status = ERR_ALREADYREGISTRED;
        response.m_content = "You are already registered";
        return response;
    }
    if (m_Model->getPassword() != t_request.m_content)
    {
        response.m_status = ERR_PASSWDMISMATCH;
        response.m_content = "Password incorrect";
        return response;
    }
    client->setStatus(AUTHENTICATED2);

    LOG("Client " + std::to_string(t_fd) + " authenticated");

    response.m_status = NO_REPLY;
    return response;
}

RequestBody Pass::parse(const std::string &t_line)
{
    DEBUG_FUNC();
    RequestBody request;
    std::istringstream iss(t_line);
    iss >> request.m_command; // Pass
    iss >> request.m_content;
    return request;
}
