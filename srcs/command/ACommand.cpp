#include "ACommand.hpp"

ResponseBody ACommand::start(int t_fd, const std::string &t_line)
{
    DEBUG_LOG();
    ResponseBody response;
    RequestBody request;

    // if (m_Model->getClient(t_fd) == NULL)
    // {
    //     response.m_status = ERR_NOSUCHNICK;
    //     return response;
    // }
    request = parse(t_line);
    response = run(t_fd, request);
    return response;
}
