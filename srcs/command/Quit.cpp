#include "Quit.hpp"
#include "../Model/Model.hpp"

Quit::Quit()
{
    DEBUG_LOG(__func__);
}
Quit::~Quit()
{
    DEBUG_LOG(__func__);
}

// Numeric Replies:
//            None.
//    Examples:
//    QUIT :Gone to have lunch        ; Preferred message format.

ResponseBody Quit::run()
{
    DEBUG_LOG(__func__);
    ResponseBody response;
    response.m_command = "QUIT";
    // response.m_status = ;

    m_Model->removeClient(m_request.m_fd);
    LOG("Client disconnected: " + to_string(m_request.m_fd) + "QUIT :Gone to have lunch");
    return response;
}
