#include "Part.hpp"
#include "../Model/Model.hpp"

Part::Part()
{
    DEBUG_LOG();
}
Part::~Part()
{
    DEBUG_LOG();
}

// Numeric Replies:
//            ERR_NEEDMOREPARAMS              ERR_NOSUCHCHANNEL
//            ERR_NOTONCHANNEL
//    Examples:
//    PART #twilight_zone             ; leave channel "#twilight_zone"
//    PART #oz-ops,&group5            ; leave both channels "&group5" and
//                                    "#oz-ops".

ResponseBody Part::start()
{
    DEBUG_LOG();
    ResponseBody response;
    response.m_command = "PART";
    if (m_Model->getChannel(id_hash(m_request.m_channel)) != NULL)
    {
        m_Model->addHub(m_request.m_fd, id_hash(m_request.m_channel), MEMBER);
        return response;
    }
    m_Model->addChannel(m_request.m_channel);
    m_Model->addHub(m_request.m_fd, id_hash(m_request.m_channel), ADMIN);

    return response;
}
