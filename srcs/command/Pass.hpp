#pragma once
#include "ACommand.hpp"

class Pass : public ACommand
{
public:
    Pass();
    ~Pass();

    ResponseBody start();
    void parse(int t_fd, const std::string &t_buffer);
};
