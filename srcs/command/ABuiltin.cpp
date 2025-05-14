#include "ABuiltin.hpp"

#include "../Model/Model.hpp"

ResponseBody ABuiltin::start(int t_fd, const std::string &t_line)
{
    DEBUG_LOG();
    RequestBody request;

    request = parse(t_line);
    if (request.m_status == ERR_NEEDMOREPARAMS)
    {
        return ResponseBody(ERR_NEEDMOREPARAMS, "Not enough parameters");
    }
    ResponseBody response = run(t_fd, request);

    return response;
}
