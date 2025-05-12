#pragma once
#include "ACommand.hpp"

class Part : public ACommand
{
public:
    Part();
    ~Part();

    ResponseBody start();
    void parse(int t_fd, const std::string &t_buffer);
};
