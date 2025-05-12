#include "Pass.hpp"
#include "../Model/Model.hpp"

Pass::Pass()
{
    DEBUG_LOG();
}
Pass::~Pass()
{
    DEBUG_LOG();
}

// ERR_NEEDMOREPARAMS              ERR_ALREADYREGISTRED
ResponseBody Pass::start()
{
    DEBUG_LOG();
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
