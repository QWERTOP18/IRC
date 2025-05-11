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

ResponseBody Quit::run()
{
    DEBUG_LOG(__func__);
    ResponseBody response;
    // response.m_status = ;

    m_Model->removeClient(m_request.m_fd);
    return response;
}
