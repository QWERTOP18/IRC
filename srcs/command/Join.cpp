#include "Join.hpp"
#include "../Model/Model.hpp"

Join::Join()
{
    DEBUG_LOG(__func__);
}
Join::~Join()
{
    DEBUG_LOG(__func__);
}

ResponseBody Join::run()
{
    DEBUG_LOG(__func__);
    ResponseBody response;
    response.m_command = "JOIN";
    if (m_Model->getChannel(id_hash(m_request.m_channel)) != NULL)
    {
        m_Model->addHub(m_request.m_fd, id_hash(m_request.m_channel), MEMBER);
        return response;
    }
    m_Model->addChannel(m_request.m_channel);
    m_Model->addHub(m_request.m_fd, id_hash(m_request.m_channel), ADMIN);

    return response;
}
