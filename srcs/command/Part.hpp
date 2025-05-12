#pragma once
#include "ACommand.hpp"

class Part : public ACommand
{
public:
    Part();
    ~Part();

    ResponseBody run(int t_fd, RequestBody t_request);
    RequestBody parse(const std::string &t_line);
};
