#pragma once
#include "ACommand.hpp"

class Join : public ACommand
{
public:
    Join();
    ~Join();

    ResponseBody start();
    void parse(int t_fd, const std::string &t_buffer);
};
