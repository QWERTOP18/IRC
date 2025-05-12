#pragma once
#include "ACommand.hpp"

class Quit : public ACommand
{
public:
    Quit();
    ~Quit();

    ResponseBody start();
    void parse(int t_fd, const std::string &t_buffer);
};
