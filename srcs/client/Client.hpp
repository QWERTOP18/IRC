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

class Client
{
private:
    int m_fd;
    std::string m_buffer;
    std::string _hostname;

    std::string _nickname;
    std::string _username;
    std::string _realname;

public:
    Client(int fd);
    ~Client();
};
