/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:40:30 by ymizukam          #+#    #+#             */
/*   Updated: 2025/05/07 07:51:10 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "macro.hpp"
#include "../Command/ACommand.hpp"

class Client
{
private:
    ID m_fd; // fd
    State m_status;
    std::string m_buf_read;

    std::string m_hostname;
    std::string m_nickname;
    std::string m_username;
    std::string m_realname;

public:
    Client(int fd);
    ~Client();
    int getFd() const { return m_fd; }
    State getStatus() const { return m_status; }
    std::string &getBuffer() { return m_buf_read; }
    const std::string &getNickname() const { return m_nickname; }
    const std::string &getUsername() const { return m_username; }
    const std::string &getRealname() const { return m_realname; }
    const std::string &getHostname() const { return m_hostname; }

    const std::string getClientInfo() const
    {
        return m_nickname + "!" + m_username + "@" + m_hostname;
    }

    void setNickname(const std::string &nickname) { m_nickname = nickname; }
    void setUsername(const std::string &username) { m_username = username; }
    void setRealname(const std::string &realname) { m_realname = realname; }
    void setHostname(const std::string &hostname) { m_hostname = hostname; }
    void setFd(int fd) { m_fd = fd; }
    void setStatus(State status) { m_status = status; }
};
