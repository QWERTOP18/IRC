#pragma once
#include "ACommand.hpp"

class Kick : public ACommand
{
public:
    Kick();
    Kick(Model *t_model);
    ~Kick();

    ResponseBody run(int t_fd, RequestBody t_request);
    RequestBody parse(const std::string &t_line);
};
