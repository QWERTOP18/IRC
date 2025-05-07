/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:41:12 by ymizukam          #+#    #+#             */
/*   Updated: 2025/05/07 07:53:23 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "macro.hpp"
#include "../client/ClientList.hpp"

class Channel
{
private:
    std::string m_name;
    // std::string m_topic;
    std::string m_password;
    int m_limit;
    bool m_key;
    ClientList m_Clients;

public:
    Channel();
    ~Channel();
};
