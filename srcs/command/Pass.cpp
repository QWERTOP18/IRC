#include "Pass.hpp"
#include "../Model/Model.hpp"

Pass::Pass()
{
    DEBUG_LOG(__func__);
}
Pass::~Pass()
{
    DEBUG_LOG(__func__);
}

// ERR_NEEDMOREPARAMS              ERR_ALREADYREGISTRED
ResponseBody Pass::run()
{
    DEBUG_LOG(__func__);
    ResponseBody response;
    if (m_request.m_content != m_Model->getPassword())
    {
        response.m_status = ERR_PASSWDMISMATCH;
        return response;
    }
    if (m_Model->getClient(m_request.m_fd)->getStatus() > AUTHENTICATED)
    {
        response.m_status = 462;
        response.m_content = "You are already registered.";
        return response;
    }

    m_Model->getClient(m_request.m_fd)->setStatus(AUTHENTICATED);
    response.m_status = 1;

    return response;
}
