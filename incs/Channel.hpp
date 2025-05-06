/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:41:12 by ymizukam          #+#    #+#             */
/*   Updated: 2025/05/07 06:46:05 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Macro.hpp"

class Channel
{
private:
    std::string m_name;
    // std::string m_topic;
    std::string m_password;
    int m_limit;
    bool m_private;

public:
    Channel(const std::string &t_name,
            const std::string &t_password = "",
            int t_limit = 0,
            bool t_private = false);
    ~Channel();
};
