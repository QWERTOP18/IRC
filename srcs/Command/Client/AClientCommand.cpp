#include "AClientCommand.hpp"

ResponseBody AClientCommand::start(int t_fd, const std::string &t_line)
{
    DEBUG_FUNC();
    RequestBody request;

    request = parse(t_line);
    if (request.m_status == ERR_NEEDMOREPARAMS)
    {
        return ResponseBody(ERR_NEEDMOREPARAMS, "Not enough parameters");
    }
    ResponseBody response = run(t_fd, request);

    return response;
}
