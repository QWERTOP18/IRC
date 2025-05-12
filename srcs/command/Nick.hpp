#pragma once
#include "ACommand.hpp"

class Nick : public ACommand
{
public:
    Nick();
    ~Nick();

    ResponseBody start();
    void parse(int t_fd, const std::string &t_buffer);
};
