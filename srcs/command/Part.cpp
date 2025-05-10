#include "Part.hpp"
#include "../Model/Model.hpp"

Part::Part()
{
    DEBUG_LOG(__func__);
}
Part::~Part()
{
    DEBUG_LOG(__func__);
}

ResponseBody Part::run(RequestBody t_request)
{
    DEBUG_LOG(__func__);
    ResponseBody response;
    if (m_Model->getChannel(id_hash(t_request.m_channel)) != NULL)
    {
        m_Model->addHub(t_request.m_fd, id_hash(t_request.m_channel), MEMBER);
        return response;
    }
    m_Model->addChannel(t_request.m_channel);
    m_Model->addHub(t_request.m_fd, id_hash(t_request.m_channel), ADMIN);

    return response;
}
