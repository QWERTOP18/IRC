#include "Nick.hpp"

Nick::Nick()
{
    DEBUG_FUNC();
}
Nick::Nick(Model *t_model) : ACommandBase(t_model)
{
    DEBUG_FUNC();
}
Nick::~Nick()
{
    DEBUG_FUNC();
}
ResponseBody Nick::run(int t_fd, RequestBody t_request)
{
    DEBUG_FUNC();
    ResponseBody response;
    Client *client = m_Model->getClient(t_fd);
    if (client->getStatus() > AUTHENTICATED_NICK3)
    {
        return ResponseBody(ERR_ALREADYREGISTRED, "You are already registered");
    }
    if (client->getStatus() < AUTHENTICATED2)
    {
        return ResponseBody(ERR_NOLOGIN, "You need to login first");
    }
    if (t_request.m_content.length() > 9)
    {
        return ResponseBody(ERR_ERRONEUSNICKNAME, "Nickname is too long");
    }
    if (m_Model->isNickNameInUse(t_request.m_content))
    {
        return ResponseBody(ERR_NICKNAMEINUSE, "Nickname is already in use");
    }

    client->setNickname(t_request.m_content);

    client->setStatus(AUTHENTICATED_NICK3);
    response.m_status = RPL_WELCOME;
    response.m_content = "Welcome to the  Network, " + client->getNickname();

    // else
    // {
    //     response.m_status = NO_REPLY;
    // }

    // LOG("Client " + to_string(t_fd) + "  is now known as " + t_request.m_content);

    return response;
}

RequestBody Nick::parse(const std::string &t_line)
{
    DEBUG_FUNC();
    RequestBody request;
    std::istringstream iss(t_line);
    iss >> request.m_command; // NICK
    iss >> request.m_content;
    if (request.m_content.empty())
    {
        request.m_status = ERR_NONICKNAMEGIVEN;
    }

    return request;
}
