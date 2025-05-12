// #include "PrivMsg.hpp"
// #include "../Model/Model.hpp"

// PrivMsg::PrivMsg()
// {
//     DEBUG_LOG();
// }
// PrivMsg::~PrivMsg()
// {
//     DEBUG_LOG();
// }

// // Numeric Replies:
// //            ERR_NORECIPIENT                 ERR_NOTEXTTOSEND
// //            ERR_CANNOTSENDTOCHAN            ERR_NOTOPLEVEL
// //            ERR_WILDTOPLEVEL                ERR_TOOMANYTARGETS
// //            ERR_NOSUCHNICK
// //            RPL_AWAY
// //    Examples:
// // :Angel PRIVMSG Wiz :Hello are you receiving this message ?
// //                                 ; Message from Angel to Wiz.

// ResponseBody PrivMsg::start()
// {
//     DEBUG_LOG();
//     ResponseBody response;
//     response.m_command = "PRIVMSG";
//     response.m_fd = m_request.m_fd;

//     if (m_request.m_content.empty())
//     {
//         response.m_status = ERR_NOTEXTTOSEND;
//         response.m_content = "No text to send";
//         return response;
//     }

//     if (m_request.m_channel.empty() && m_request.m_nickname.empty())
//     {
//         response.m_status = ERR_NORECIPIENT;
//         response.m_content = "No recipient given";
//         return response;
//     }
//     // channelに送信する場合
//     if (!m_request.m_channel.empty())
//     {
//         Channel *channel = m_Model->getChannel(id_hash(m_request.m_channel));
//         if (channel == NULL)
//         {
//             response.m_status = ERR_NOSUCHCHANNEL;
//             response.m_content = "No such channel: " + m_request.m_channel;
//             return response;
//         }
//         if (m_Model->isClientOnChannel(m_request.m_fd, channel->getId()) == false)
//         {
//             response.m_status = ERR_NOTONCHANNEL;
//             response.m_content = "You're not on that channel: " + m_request.m_channel;
//             return response;
//         }
//         std::string message = ":" + m_Model->getClient(m_request.m_fd)->getNickname() + " PRIVMSG " + m_request.m_channel + " :" + m_request.m_content;
//         broadcast(m_request.m_fd, message, channel->getId());
//     }
//     // nicknameに送信する場合
//     else if (!m_request.m_nickname.empty())
//     {
//         Client *client = m_Model->getClient(m_request.m_nickname);
//         if (client == NULL)
//         {
//             response.m_status = ERR_NOSUCHNICK;
//             response.m_content = "No such nick: " + m_request.m_nickname;
//             return response;
//         }
//         std::string message = ":" + m_Model->getClient(m_request.m_fd)->getNickname() + " PRIVMSG " + m_request.m_nickname + " :" + m_request.m_content;
//         sendToClient(client->getFd(), message);
//     }
//     else
//     {
//         response.m_status = ERR_NORECIPIENT;
//         response.m_content = "No recipient given";
//     }

//     return response;
// }
