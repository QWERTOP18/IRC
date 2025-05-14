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

#include "../Controller/Controller.hpp"

class Server
{
protected:
    std::string m_password;
    int m_port;
    int m_sokcet;
    pollfd m_pollfd;

    Model *m_Model;
    Controller *m_Controller;

public:
    Server(const std::string &t_port,
           const std::string &t_password,
           Model *model, Controller *controller);
    Server();

    ~Server();

    void start();
    void poll();

protected:
    void setPort(const std::string &t_port);
    void setPassword(const std::string &t_password);
    void setSocket();
};
