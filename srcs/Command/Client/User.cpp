#include "User.hpp"

User::User()
{
    DEBUG_FUNC();
}
User::User(Model *t_model) : ACommandBase(t_model)
{
    DEBUG_FUNC();
}
User::~User()
{
    DEBUG_FUNC();
}
ResponseBody User::run(int t_fd, RequestBody t_request)
{
    DEBUG_FUNC();
    Client *cl = m_Model->getClient(t_fd);
    if (cl->getStatus() < AUTHENTICATED_NICK3)
    {
        return ResponseBody(ERR_NONICKNAMEGIVEN, "No NickName was given");
    }

    cl->setUsername(t_request.m_content);
    cl->setRealname(t_request.m_content2);
    cl->setHostname("localhost");

    cl->setStatus(REGISTERED);

    LOG("Client " + to_string(t_fd) + "  is now registered " + t_request.m_content);
    return ResponseBody(RPL_WELCOME, cl->getClientInfo());
}

RequestBody User::parse(const std::string &t_line)
{
    DEBUG_FUNC();
    RequestBody request;
    std::istringstream iss(t_line);
    iss >> request.m_command; // NICK
    iss >> request.m_content;
    iss >> request.m_content2;
    // iss >> request.m_content;
    // realnameなども取れたほうが嬉しいかもしれない
    return request;
}
