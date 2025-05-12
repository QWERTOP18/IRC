// #include "Invite.hpp"

// #include "../Model/Model.hpp"

// Invite::Invite()
// {
//     DEBUG_LOG();
// }
// Invite::~Invite()
// {
//     DEBUG_LOG();
// }

// ResponseBody Invite::start(int t_fd, const std::string &t_line)
// {
//     DEBUG_LOG();
//     ResponseBody response;
//     response.m_command = "INVITE";
//     if (m_Model->getClient(m_request.m_fd) == NULL)
//     {
//         response.m_status = ERR_NOSUCHNICK;
//         return response;
//     }
//     parse(m_request.m_fd, t_line);
//     response = run();
//     return response;
// }

// void Invite::parse(int t_fd, const std::string &t_buffer)
// {
//     DEBUG_LOG();
//     m_request.m_fd = t_fd;
//     std::istringstream iss(t_buffer);
//     std::string command;
//     iss >> command;                     // INVITE
//     iss >> m_request.m_target_nickname; // target_nick
//     iss >> m_request.m_channel;         // channel_name
// }

// ResponseBody Invite::run()
// {
//     DEBUG_LOG();
//     ResponseBody response;
//     response.m_command = "INVITE";
//     if (m_Model->getClient(m_request.m_fd) == NULL)
//     {
//         response.m_status = ERR_NOSUCHNICK;
//         return response;
//     }

//     if (m_request.m_channel.empty())
//     {
//         response.m_status = ERR_NEEDMOREPARAMS;
//         return response;
//     }
//     if (m_Model->getChannel(id_hash(m_request.m_channel)) == NULL)
//     {
//         response.m_status = ERR_NOSUCHCHANNEL;

//         return response;
//     }
//     {
//         response.m_status = 401;
//         return response;
//     }

//     if (m_Model->getClient(m_request.m_fd)->getStatus() < AUTHENTICATED)
//     {
//         response.m_status = 451;
//         return response;
//     }
//     // if (m_Model->getClient(m_request.m_fd)->isOperator(channel_name) == false)
//     // {
//     //     response.m_status = 482;
//     //     return response;
//     // }

//     // if (m_Model->getClient(target_nick)->isInChannel(channel_name))
//     // {
//     //     response.m_status = 443;
//     //     return response;
//     // 443     ERR_USERONCHANNEL
//     //                     "<user> <channel> :is already on channel"

//     //             - Returned when a client tries to invite a user to a
//     //               channel they are already on.
//     // }

//     m_Model->addHub(m_Model->getClient(m_request.m_fd)->getFd(), id_hash(m_request.m_channel), INVITED);
//     return response;
// }
