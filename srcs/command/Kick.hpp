#pragma once
#include "ACommand.hpp"

class Kick : public ACommand
{
public:
    Kick();
    ~Kick();
    ResponseBody run(RequestBody t_request);
    RequestBody parse(const std::string &t_line);
};
