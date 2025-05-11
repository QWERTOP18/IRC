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

ResponseBody Part::run()
{
    DEBUG_LOG(__func__);
    ResponseBody response;
    if (m_Model->getChannel(id_hash(m_request.m_channel)) != NULL)
    {
        m_Model->addHub(m_request.m_fd, id_hash(m_request.m_channel), MEMBER);
        return response;
    }
    m_Model->addChannel(m_request.m_channel);
    m_Model->addHub(m_request.m_fd, id_hash(m_request.m_channel), ADMIN);

    return response;
}
