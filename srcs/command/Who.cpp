#include "Who.hpp"
#include "../Model/Model.hpp"

Who::Who()
{
    DEBUG_LOG(__func__);
}
Who::~Who()
{
    DEBUG_LOG(__func__);
}

// Numeric Replies:
//            ERR_NOSUCHSERVER
//            RPL_WHOREPLY                    RPL_ENDOFWHO
//    Examples:
//    WHO *.fi                        ; List all users who match against
//                                    "*.fi".
//    WHO jto* o                      ; List all users with a match against
//                                    "jto*" if they are an operator.

ResponseBody Who::run()
{
    DEBUG_LOG(__func__);
    ResponseBody response;
    response.m_command = "WHO";
    if (m_request.m_nickname.empty())
    {
        response.m_status = ERR_NOSUCHSERVER;
        return response;
    }
    Client *client = m_Model->getClient(m_request.m_fd);
    if (client == NULL)
    {
        response.m_status = RPL_ENDOFWHO;
        return response;
    }

    response.m_status = RPL_WHOREPLY;
    response.m_nickname = client->getNickname();
    response.m_hostname = client->getHostname();
    response.m_content = "is a user on the server";

    return response;
}
