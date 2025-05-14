#pragma once

#include <string>

class IBody
{
protected:
public:
    int m_status;
    std::string m_command;
    int m_fd;
    std::string m_nickname;
    std::string m_target_channel;
    std::string m_target_nickname;

    std::string m_content;

    IBody() {};
    virtual ~IBody() {}
};
