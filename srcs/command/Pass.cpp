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
    if (t_request.m_content == m_Model->getPassword())
    {
        response.m_status = 200;
    }
    else
    {
        response.m_status = 401;
        response.m_content = "Invalid password";
    }
    return response;
}
