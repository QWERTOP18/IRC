#include "Join.hpp"
#include "../Model/Model.hpp"

Join::Join()
{
    DEBUG_LOG();
}
Join::~Join()
{
    DEBUG_LOG();
}

void Join::parse(int t_fd, const std::string &t_buffer)
{
    DEBUG_LOG();
    m_request.m_fd = t_fd;
    std::istringstream iss(t_buffer);
    std::string command;
    iss >> command;                     // JOIN
    iss >> m_request.m_channel;         // channel_name
    iss >> m_request.m_target_nickname; // target_nick
}

ResponseBody Join::start()
{
    DEBUG_LOG();
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
