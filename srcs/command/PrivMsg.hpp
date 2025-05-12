#pragma once
#include "ACommand.hpp"

class PrivMsg : public ACommand
{
public:
    PrivMsg();
    ~PrivMsg();

    ResponseBody start();
    void parse(int t_fd, const std::string &t_buffer);
};
