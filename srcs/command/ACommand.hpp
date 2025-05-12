#pragma once
#include "macro.hpp"

class Model; // Forward declaration

class ACommand
{
protected:
    Model *m_Model;
    int m_fd;

public:
    RequestBody m_request;
    ACommand();
    ACommand(Model *t_model);
    virtual ~ACommand();

    void setModel(Model *t_model) { m_Model = t_model; }
    void setFd(int t_fd) { m_fd = t_fd; }
    // void setRequest(const RequestBody &t_request) { m_request = t_request; }
    virtual ResponseBody start() = 0;
    virtual void parse(int t_fd, const std::string &t_buffer) = 0;

    void broadcast(int fd, const std::string &t_message, int t_channel_id);
    void sendToClient(int fd, const std::string &t_message);
};
