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
    if (t_request.m_content.empty())
    {
        return ResponseBody(ERR_NONICKNAMEGIVEN, "No NickName was given");
    }
    if (m_Model->isNickNameInUse(t_request.m_content))
    {
        return ResponseBody(ERR_NICKNAMEINUSE, "Nickname is already in use");
    }
    Client *client = m_Model->getClient(t_fd);

    client->setNickname(t_request.m_content);
    if (client->getStatus() == CONNECTED1)
    {
        client->setStatus(AUTHENTICATED_NICK3);
        response.m_status = RPL_WELCOME;
        // :server 001 <nick> :Welcome to the <network> Network, <nick>[!<user>@<host>]
        response.m_content = "Welcome to the  Network, " + client->getNickname();
    }
    else
    {
        response.m_status = NO_REPLY;
    }

    LOG("Client " + std::to_string(t_fd) + "  is now known as " + t_request.m_content);

    return response;
}

RequestBody Nick::parse(const std::string &t_line)
{
    DEBUG_FUNC();
    RequestBody request;
    std::istringstream iss(t_line);
    iss >> request.m_command; // NICK
    iss >> request.m_content;
    return request;
}
