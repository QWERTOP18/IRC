#include "ACommand.hpp"
#include "../Model/Model.hpp"

ResponseBody ACommand::start(int t_fd, const std::string &t_line)
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
    response = run(t_fd, request);
    return response;
}
