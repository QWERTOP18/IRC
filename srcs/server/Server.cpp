/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 09:19:31 by ymizukam          #+#    #+#             */
/*   Updated: 2025/05/06 12:30:31 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

Server::Server(const std::string &t_port, const std::string &t_password)
{
    setPort(t_port);
    setPassword(t_password);
    setSocket();
}

Server::~Server()
{
    DEBUG_LOG(__func__);
}

void Server::start()
{
    DEBUG_LOG(__func__);
    LOG("Server started on port" + to_string(m_port));
}

void Server::run()
{
    DEBUG_LOG(__func__);

    {
        while (1)
        {
            // pollfd を一つにまとめる（server socket + clients）
            // poll にためにsocketとclientをまとめないといけない
            // ClientListを継承したPollfdListを作る todo!
            std::vector<pollfd> fds = m_CLIENTS.getPollFds();
            fds.insert(fds.begin(), {m_socket, POLLIN, 0});

            if (poll(fds.data(), fds.size(), -1) < 0)
                throw std::runtime_error("poll() failed");

            if (fds[0].revents & POLLIN)
                m_CLIENTS.add();
            for (size_t i = 0; i < fds.size(); ++i)
            {
                if (fds[i].revents == 0)
                    continue;

                if (i == 0) // server socket
                {
                }
                else // client socket
                {
                    m_CLIENTS.handleEvent(fds[i]);
                }
            }
        }
    }
}