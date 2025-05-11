#include "PrivMsg.hpp"
#include "../Model/Model.hpp"

PrivMsg::PrivMsg()
{
    DEBUG_LOG(__func__);
}
PrivMsg::~PrivMsg()
{
    DEBUG_LOG(__func__);
}

// Numeric Replies:
//            ERR_NORECIPIENT                 ERR_NOTEXTTOSEND
//            ERR_CANNOTSENDTOCHAN            ERR_NOTOPLEVEL
//            ERR_WILDTOPLEVEL                ERR_TOOMANYTARGETS
//            ERR_NOSUCHNICK
//            RPL_AWAY
//    Examples:
// :Angel PRIVMSG Wiz :Hello are you receiving this message ?
//                                 ; Message from Angel to Wiz.

ResponseBody PrivMsg::run()
{
    DEBUG_LOG(__func__);
    ResponseBody response;
    // response.m_status = ;

    m_Model->removeClient(m_request.m_fd);
    LOG("Client disconnected: " + to_string(m_request.m_fd) + "QUIT :Gone to have lunch");
    return response;
}
