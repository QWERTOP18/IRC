#include "Quit.hpp"
#include "../Model/Model.hpp"

Quit::Quit()
{
    DEBUG_LOG();
}
Quit::Quit(Model *t_model) : ACommandBase(t_model)
{
    DEBUG_LOG();
}
Quit::~Quit()
{
    DEBUG_LOG();
}

// Numeric Replies:
//            None.
//    Examples:
//    QUIT :Gone to have lunch        ; Preferred message format.

ResponseBody Quit::run(int t_fd, RequestBody t_request)
{
    DEBUG_LOG();
    ResponseBody response;
    (void)t_request;

    if (m_Model->getClient(t_fd) == NULL)
    {
        response.m_status = ERR_NOSUCHNICK;
        return response;
    }

    m_Model->removeClient(t_fd);
    response.m_status = NO_REPLY;
    LOG("Client disconnected: " + to_string(t_fd) + "QUIT :Gone to have lunch");

    return response;
}

RequestBody Quit::parse(const std::string &t_line)
{
    DEBUG_LOG();
    RequestBody request;
    std::istringstream iss(t_line);
    iss >> request.m_command; // QUIT
    iss >> request.m_content;
    return request;
}
