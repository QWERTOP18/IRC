#include "User.hpp"
#include "../Model/Model.hpp"
User::User()
{
    DEBUG_LOG();
}
User::User(Model *t_model) : ACommandBase(t_model)
{
    DEBUG_LOG();
}
User::~User()
{
    DEBUG_LOG();
}
ResponseBody User::run(int t_fd, RequestBody t_request)
{
    DEBUG_LOG();

    ResponseBody response;
    Client *client = m_Model->getClient(t_fd);
    if (client == NULL)
    {
        // return ResponseBody(ERR_NOTREGISTERED, "You have not registered");
        response.m_status = ERR_NOTREGISTERED;
        return response;
    }

    return response;
}

RequestBody User::parse(const std::string &t_line)
{
    DEBUG_LOG();
    RequestBody request;
    std::istringstream iss(t_line);
    iss >> request.m_command; // NICK
    iss >> request.m_content;
    iss >> request.m_content;
    iss >> request.m_content;
    return request;
}
