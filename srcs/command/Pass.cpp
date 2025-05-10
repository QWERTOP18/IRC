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

ResponseBody Pass::run(RequestBody t_request)
{
    DEBUG_LOG(__func__);
    ResponseBody response;
    if (t_request.m_content != m_Model->getPassword())
    {
        response.m_status = 464;
        return response;
    }
    if (m_Model->getClient(t_request.m_fd)->getStatus() > AUTHENTICATED)
    {
        response.m_status = 462;
        response.m_content = "You are already registered.";
        return response;
    }

    m_Model->getClient(t_request.m_fd)->setStatus(AUTHENTICATED);
    response.m_status = 1;

    return response;
}
