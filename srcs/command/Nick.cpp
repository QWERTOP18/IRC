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
        return response;
    }
    if (m_Model->isNickNameInUse(t_request.m_content))
    {
        response.m_status = ERR_NICKNAMEINUSE;
        return response;
    }
    Client *client = m_Model->getClient(t_fd);
    client->setNickname(t_request.m_content);

    LOG("Client " + std::to_string(t_fd) + " changed nickname to " + t_request.m_content);

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
