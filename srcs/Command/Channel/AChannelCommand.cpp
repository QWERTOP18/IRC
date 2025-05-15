#include "AChannelCommand.hpp"

ResponseBody AChannelCommand::start(int t_fd, const std::string &t_line)
{
    DEBUG_FUNC();
    ResponseBody response;
    RequestBody request;

    Client *client = m_Model->getClient(t_fd);
    // if (client == NULL)
    //     throw std::runtime_error("Client not found");

    if (client->getStatus() < REGISTERED)
    {
        return ResponseBody(ERR_NOTREGISTERED, "You have not registered");
    }

    request = parse(t_line);
    if (request.m_status == ERR_NEEDMOREPARAMS)
    {
        return ResponseBody(ERR_NEEDMOREPARAMS, "Not enough parameters");
    }
    Channel *ch = m_Model->getChannel(request.m_target_channel);
    if (ch == NULL)
    {
        return ResponseBody(ERR_NOSUCHCHANNEL, "No such channel");
    }
    if (m_Model->isClientOnChannel(t_fd, ch->getId()) == false)
    {
        return ResponseBody(ERR_NOTONCHANNEL, "You are not on the channel");
    }

    response = run(t_fd, request);
    return response;
}
