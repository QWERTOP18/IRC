#include "Quit.hpp"

Quit::Quit()
{
    DEBUG_FUNC();
}
Quit::Quit(Model *t_model) : ACommandBase(t_model)
{
    DEBUG_FUNC();
}
Quit::~Quit()
{
    DEBUG_FUNC();
}

// Numeric Replies:
//            None.
//    Examples:
//    QUIT :Gone to have lunch        ; Preferred message format.

ResponseBody Quit::run(int t_fd, RequestBody t_request)
{
    DEBUG_FUNC();
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
    DEBUG_FUNC();
    RequestBody request;
    std::istringstream iss(t_line);
    iss >> request.m_command; // QUIT
    iss >> request.m_content;
    return request;
}
