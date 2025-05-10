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

class Channel
{
private:
    ID m_id;
    std::string m_name;
    std::string m_topic;
    std::string m_key;
    int m_limit;

public:
    Channel(const std::string &name);
    ~Channel();
    ID getId() const { return m_id; }
    const std::string &getName() const { return m_name; }
    const std::string &getTopic() const { return m_topic; }

    void setTopic(const std::string &topic) { m_topic = topic; }
    void setKey(const std::string &key) { m_key = key; }
    void setLimit(int limit) { m_limit = limit; }

private:
};
