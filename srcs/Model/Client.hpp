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
    int m_fd;
    std::string m_buffer;
    std::string m_hostname;
    std::string m_nickname;
    std::string m_username;
    std::string m_realname;

public:
    Client(int fd);
    ~Client();
    int getFd() const { return m_fd; }
};
