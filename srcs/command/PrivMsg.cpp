#include "PrivMsg.hpp"
#include "../Model/Model.hpp"

PrivMsg::PrivMsg()
{
    DEBUG_LOG();
}

PrivMsg::PrivMsg(Model *t_model) : ACommandBase(t_model)
{
    DEBUG_LOG();
}

PrivMsg::~PrivMsg()
{
    DEBUG_LOG();
}

RequestBody PrivMsg::parse(const std::string &t_line)
{
    DEBUG_LOG();
    std::istringstream iss(t_line);
    RequestBody request;
    iss >> request.m_command;         // PrivMsg
    iss >> request.m_target_nickname; // nick_name
    iss >> request.m_content;         // message
    return request;
}

ResponseBody PrivMsg::run(int t_fd, RequestBody t_request)
{
    DEBUG_LOG();
    ResponseBody response;
    response.m_command = "PRIVMSG";

    if (t_request.m_target_nickname.empty() || t_request.m_content.empty())
    {
        response.m_status = ERR_NEEDMOREPARAMS;
        response.m_content = "Not enough parameters";
        return response;
    }

    Client *target_client = m_Model->getClient(t_request.m_target_nickname);
    if (target_client == NULL)
    {
        response.m_status = ERR_NOSUCHNICK;
        response.m_content = "No such nick";
        return response;
    }

    this->sendToClient(t_fd, target_client->getFd(), t_request.m_content);
    response.m_status = NO_REPLY;

    return response;
}
