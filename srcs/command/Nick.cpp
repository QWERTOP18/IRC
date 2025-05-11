#include "Nick.hpp"
#include "../Model/Model.hpp"

Nick::Nick()
{
    DEBUG_LOG(__func__);
}
Nick::~Nick()
{
    DEBUG_LOG(__func__);
}

// Numeric Replies:
//            ERR_NONICKNAMEGIVEN             ERR_ERRONEUSNICKNAME
//            ERR_NICKNAMEINUSE               ERR_NICKCOLLISION
//    Example:
//    NICK Wiz                        ; Introducing new nick "Wiz".
//    :WiZ NICK Kilroy                ; WiZ changed his nickname to Kilroy.

ResponseBody Nick::run()
{
    DEBUG_LOG(__func__);
    ResponseBody response;
    response.m_command = "NICK";
    if (m_request.m_nickname.empty())
    {
        response.m_status = ERR_NONICKNAMEGIVEN;
        return response;
    }
    if (m_Model->isNickNameInUse(m_request.m_nickname) == true)
    {
        response.m_status = ERR_NICKNAMEINUSE;
        return response;
    }

    m_Model->getClient(m_request.m_fd)->setNickname(m_request.m_nickname);
    LOG("Client nickname set: " + to_string(m_request.m_fd) + " NICK " + m_request.m_nickname);
    return response;
}
