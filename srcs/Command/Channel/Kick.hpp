#pragma once
#include "AChannelCommand.hpp"

class Kick : public AChannelCommand
{
public:
    Kick();
    Kick(Model *t_model);
    ~Kick();

    ResponseBody run(int t_fd, RequestBody t_request);
    RequestBody parse(const std::string &t_line);
};
