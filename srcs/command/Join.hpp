#pragma once
#include "ACommand.hpp"

class Join : public ACommand
{
public:
    Join();
    ~Join();

    ResponseBody run(RequestBody t_request);
    RequestBody parse(const std::string &t_line);
};
