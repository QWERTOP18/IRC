/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ChannelList.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:40:37 by ymizukam          #+#    #+#             */
/*   Updated: 2025/05/06 11:47:43 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "macro.hpp"

#include "Channel.hpp"
#include <map>

class ChannelList
{
private:
    std::map<std::string, Channel *> m_channels;

public:
    ChannelList();
    ~ChannelList();
    void append(const std::string &t_name,
                const std::string &t_password = "",
                int t_limit = 0,
                bool t_private = false);
    void remove(const std::string &t_name);
};
