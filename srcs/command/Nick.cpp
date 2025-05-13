#include "Nick.hpp"
#include "../Model/Model.hpp"
Nick::Nick()
{
    DEBUG_LOG();
}
Nick::Nick(Model *t_model) : ACommandBase(t_model)
{
    DEBUG_LOG();
}
Nick::~Nick()
{
    DEBUG_LOG();
}
ResponseBody Nick::run(int t_fd, RequestBody t_request)
{
    DEBUG_LOG();
    ResponseBody response;
    if (t_request.m_content.empty())
    {
        response.m_status = ERR_NONICKNAMEGIVEN;
        response.m_content = "No NickName was given";
        return response;
    }
    if (m_Model->isNickNameInUse(t_request.m_content))
    {
        response.m_status = ERR_NICKNAMEINUSE;
        response.m_content = "Nickname is already in use";
        return response;
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
    DEBUG_LOG();
    RequestBody request;
    std::istringstream iss(t_line);
    iss >> request.m_command; // NICK
    iss >> request.m_content;
    return request;
}
