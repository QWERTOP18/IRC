#pragma once
#include "ACommand.hpp"

class Topic : public ACommand
{
public:
    Topic();
    ~Topic();

    ResponseBody run(int t_fd, RequestBody t_request);
    RequestBody parse(const std::string &t_line);
};
