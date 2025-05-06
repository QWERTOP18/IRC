/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:40:30 by ymizukam          #+#    #+#             */
/*   Updated: 2025/05/06 11:40:31 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "macro.hpp"
#include <poll.h>
class Client
{
private:
    pollfd m_pfd;
    std::string m_buffer;
    std::string _nickname;
    std::string _username;
    std::string _realname;

public:
    Client(int fd);
    ~Client();
};
