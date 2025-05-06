/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 09:19:31 by ymizukam          #+#    #+#             */
/*   Updated: 2025/05/06 09:30:55 by ymizukam         ###   ########.fr       */
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
