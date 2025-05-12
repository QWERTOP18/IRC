#pragma once
#include "ACommand.hpp"

class Pass : public ACommand
{
public:
    Pass();
    ~Pass();

    ResponseBody run(int t_fd, RequestBody t_request);
    RequestBody parse(const std::string &t_line);
};
