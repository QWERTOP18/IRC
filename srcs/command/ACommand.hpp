#pragma once
#include "macro.hpp"

class Model; // Forward declaration

class ACommand
{
protected:
    Model *m_Model;
    // int m_fd;
    virtual ResponseBody run(RequestBody t_reqest) = 0;
    virtual RequestBody parse(const std::string &t_line) = 0;

public:
    ACommand();
    ACommand(Model *t_model);
    virtual ~ACommand();
    ResponseBody start(int t_fd, const std::string &t_line);

public:
    void broadcast(const std::string &t_message, int t_channel_id);
    void sendToClient(int fd, const std::string &t_message);
};
