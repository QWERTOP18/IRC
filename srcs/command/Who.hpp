#pragma once
#include "ACommand.hpp"

class Who : public ACommand
{
public:
    Who();
    ~Who();

    void parse(int t_fd, const std::string &t_buffer);
    ResponseBody start();
};
