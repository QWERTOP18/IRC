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
    Client *client = m_Model->getClient(t_fd);

    if (client->getStatus() > CONNECTED1)
    {
        return ResponseBody(ERR_ALREADYREGISTRED, "You are already registered");
    }
    if (m_Model->getPassword() != t_request.m_content)
    {
        return ResponseBody(ERR_PASSWDMISMATCH, "Password incorrect");
    }
    client->setStatus(AUTHENTICATED2);

    LOG("Client " + to_string(t_fd) + " authenticated");

    return ResponseBody(NO_REPLY);
}

RequestBody Pass::parse(const std::string &t_line)
{
    DEBUG_FUNC();
    RequestBody request;
    std::istringstream iss(t_line);
    iss >> request.m_command; // Pass
    iss >> request.m_content;
    if (request.m_content.empty())
    {
        request.m_status = ERR_NEEDMOREPARAMS;
    }
    
    return request;
}
