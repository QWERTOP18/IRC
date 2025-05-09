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
    void setFd(int fd) { m_fd = fd; }
    void setStatus(State status) { m_status = status; }
};
