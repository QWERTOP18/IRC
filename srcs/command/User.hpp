#pragma once
#include "ACommand.hpp"

class User : public ACommand
{
public:
    User();
    User(Model *t_model);
    ~User();

    ResponseBody run(int t_fd, RequestBody t_request);
    RequestBody parse(const std::string &t_line);
};
