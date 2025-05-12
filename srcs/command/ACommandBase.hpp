#pragma once
#include "macro.hpp"

class Model; // Forward declaration

class ACommandBase
{
protected:
    Model *m_Model;
    // int m_fd;
    virtual ResponseBody run(int t_fd, RequestBody t_reqest) = 0;
    virtual RequestBody parse(const std::string &t_line) = 0;

public:
    ACommandBase();
    ACommandBase(Model *t_model);
    virtual ~ACommandBase();
    // ResponseBody start(int t_fd, const std::string &t_line);

public:
    void broadcast(int t_fd, int t_channel_id, const std::string &t_message);
    void sendToClient(int t_fd, int t_target_fd, const std::string &t_message);
};
