#pragma once
#include "ACommand.hpp"

class Kick : public ACommand
{
public:
    Kick();
    ~Kick();

    ResponseBody start();
    void parse(int t_fd, const std::string &t_buffer);
};
