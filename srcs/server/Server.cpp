/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 09:19:31 by ymizukam          #+#    #+#             */
/*   Updated: 2025/05/07 07:42:41 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

Server::Server(const std::string &t_port, const std::string &t_password)
{
    setPort(t_port);
    setPassword(t_password);
    setSocket();
    m_pollfd.fd = m_sokcet;
    m_pollfd.events = POLLIN;
    m_pollfd.revents = 0;
}

Server::~Server()
{
    DEBUG_LOG(__func__);
}

void Server::start()
{
    DEBUG_LOG(__func__);
    LOG("Server started on port" + to_string(m_port));

    while (1)
    {
        this->poll();
    }
}

void Server::poll()
{
    DEBUG_LOG(__func__);
    std::vector<pollfd> pollfds = m_Model.getPollfds();
    pollfds.push_back(m_pollfd);
    if (::poll(pollfds.data(), pollfds.size(), -1) == -1)
        throw std::runtime_error(Err::Socket::POLL_FAIL);

    for (size_t i = 0; i < pollfds.size(); ++i)
    {
        if (pollfds[i].revents & POLLIN)
        {
            if (pollfds[i].fd == m_sokcet)
            {
                int client_fd = accept(m_sokcet, NULL, NULL);
                if (client_fd < 0)
                {
                    LOG(Err::Client::ACCEPT_FAIL);
                    continue;
                }
                LOG("New client connected: " + to_string(client_fd));
                m_Model.addClient(client_fd);
            }
            else
            {
                LOG("Client request: " + to_string(pollfds[i].fd));
                m_Model.manageClientRequest(pollfds[i].fd);
            }
        }
        if (pollfds[i].revents & POLLHUP)
        {
            LOG("Client disconnected: " + to_string(pollfds[i].fd));
            m_Model.removeClient(pollfds[i].fd);
        }
    }
}
