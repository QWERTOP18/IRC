/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:41:12 by ymizukam          #+#    #+#             */
/*   Updated: 2025/05/15 10:41:13 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "macro.hpp"

enum Role
{
    NONE,
    ADMIN,
    MEMBER,
    INVITED,
    BANNED
};

struct MODE
{
    // bool b_onchannel;
    bool b_invite;
    // bool b_private;
    // bool b_secret;
    bool b_topic;
    std::string b_key;
    int b_limit;
};

class Channel
{
private:
    ID m_id;
    std::string m_name;
    std::string m_topic;
    std::string m_key;
    int m_limit;
    MODE m_mode;

public:
    Channel(const std::string &name);
    ~Channel();
    ID getId() const { return m_id; }
    const std::string &getName() const { return m_name; }
    const std::string &getTopic() const { return m_topic; }
    const std::string &getKey() const { return m_key; }
    int getLimit() const { return m_limit; }
    MODE getMode() const { return m_mode; }
    void setTopic(const std::string &topic) { m_topic = topic; }
    void setKey(const std::string &key) { m_key = key; }
    void setLimit(int limit) { m_limit = limit; }

    void setInvite(bool invite) { m_mode.b_invite = invite; }
    void setTopic(bool topic) { m_mode.b_topic = topic; }
    // void setKey(bool key) { m_mode.b_key = key; }
    // void setLimit(bool limit) { m_mode.b_limit = limit; }

private:
};
