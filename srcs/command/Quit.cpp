#include "Quit.hpp"
#include "../Model/Model.hpp"

Quit::Quit()
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

ResponseBody Quit::start()
{
    DEBUG_LOG();
    ResponseBody response;
    response.m_command = "QUIT";
    // response.m_status = ;

    m_Model->removeClient(m_request.m_fd);
    LOG("Client disconnected: " + to_string(m_request.m_fd) + "QUIT :Gone to have lunch");
    return response;
}
