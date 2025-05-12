#pragma once
#include "ACommand.hpp"

class Topic : public ACommand
{
public:
    Topic();
    ~Topic();

    void parse(int t_fd, const std::string &t_buffer);
    ResponseBody start();
};
