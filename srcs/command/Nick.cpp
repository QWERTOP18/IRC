// #include "Nick.hpp"
// #include "../Model/Model.hpp"

// Nick::Nick()
// {
//     DEBUG_LOG();
// }
// Nick::~Nick()
// {
//     DEBUG_LOG();
// }

// // Numeric Replies:
// //            ERR_NONICKNAMEGIVEN             ERR_ERRONEUSNICKNAME
// //            ERR_NICKNAMEINUSE               ERR_NICKCOLLISION
// //    Example:
// //    NICK Wiz                        ; Introducing new nick "Wiz".
// //    :WiZ NICK Kilroy                ; WiZ changed his nickname to Kilroy.

// void Nick::parse(int t_fd, const std::string &t_buffer)
// {
//     DEBUG_LOG();
//     m_request.m_fd = t_fd;
//     std::istringstream iss(t_buffer);
//     std::string command;
//     iss >> command;              // NICK
//     iss >> m_request.m_nickname; // nickname
// }

// ResponseBody Nick::start()
// {
//     DEBUG_LOG();
//     ResponseBody response;
//     response.m_command = "NICK";
//     if (m_request.m_nickname.empty())
//     {
//         response.m_status = ERR_NONICKNAMEGIVEN;
//         return response;
//     }
//     if (m_Model->isNickNameInUse(m_request.m_nickname) == true)
//     {
//         response.m_status = ERR_NICKNAMEINUSE;
//         return response;
//     }

//     m_Model->getClient(m_request.m_fd)->setNickname(m_request.m_nickname);
//     LOG("Client nickname set: " + to_string(m_request.m_fd) + " NICK " + m_request.m_nickname);
//     return response;
// }
