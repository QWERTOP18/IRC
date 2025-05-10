/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 09:19:25 by ymizukam          #+#    #+#             */
/*   Updated: 2025/05/07 20:50:36 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "macro.hpp"
#include <iostream>
#include <string>
#include <sys/socket.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <poll.h>

#include "../Model/Model.hpp"

class Server
{
private:
    std::string m_password;
    int m_port;
    int m_sokcet;
    pollfd m_pollfd;

    Model m_Model;

public:
    Server(const std::string &t_port, const std::string &t_password);
    ~Server();

    void start();
    void poll();
    // std::string const &readRequest(int fd, std::string &buffer);

private:
    void setPort(const std::string &t_port);
    void setPassword(const std::string &t_password);
    void setSocket();
};
