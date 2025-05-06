/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 09:19:25 by ymizukam          #+#    #+#             */
/*   Updated: 2025/05/06 09:19:26 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "config.hpp"
#include <iostream>
#include <string>
#include <sys/socket.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <poll.h>

class Server
{
private:
    std::string m_password;
    int m_port;
    int m_sokcet;
    int m_connect_max;

    void setPort(const std::string &t_port);
    void setPassword(const std::string &t_password);
    void setSocket();

public:
    Server(const std::string &t_port, const std::string &t_password);
    ~Server();

    void start();
};

namespace Err
{
    namespace Port
    {

        static const char *NOT_NUMERIC = "Port must be a numeric value";
        static const char *OUT_OF_RANGE = "Port must be between 6660 and 6669";
    }
    namespace Password
    {
        static const char *TOO_SHORT = "Password must be at least 4 characters long";
        static const char *LOWERCASE_MISSING = "Password must include lowercase";
        static const char *UPPERCASE_MISSING = "Password must include uppercase";
    }

    // exception Classにしてもいいかも
    namespace Socket
    {
        static const char *OPEN_FAIL = "failed to open socket";
        static const char *SETOPT_FAIL = "failed to set socket options";
        static const char *NONBLOCK_FAIL = "failed to set non-blocking mode";
        static const char *BIND_FAIL = "failed to bind socket";
        static const char *LISTEN_FAIL = "failed to listen on socket";
        static const char *ACCEPT_FAIL = "failed to accept connection";
        static const char *RECV_FAIL = "failed to read from socket";
        static const char *GETNAME_FAIL = "failed to get hostname";
        static const char *POLL_FAIL = "failed to poll file descriptor";
    }
}
