#pragma once

#include <string>

class IBody
{
protected:
public:
    std::string m_command;
    int m_fd;
    std::string m_nickname;
    std::string m_channel;
    std::string m_content;

    IBody() {};
    virtual ~IBody() {}
};
