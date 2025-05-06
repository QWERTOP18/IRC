/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClientList.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:40:33 by ymizukam          #+#    #+#             */
/*   Updated: 2025/05/06 12:23:31 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "macro.hpp"
#include <vector>
#include <map>

#include "Client.hpp"

class ClientList
{
private:
    std::map<int, Client *> m_clients;

public:
    ClientList();
    ~ClientList();

    void append(int fd);
    void remove(int fd);
    void handleEvent(const int fd);
    std::vector<pollfd> getPollFds() const;
    // void setClient(int fd, const std::string &nickname,
    //                const std::string &username, const std::string &realname);
};
