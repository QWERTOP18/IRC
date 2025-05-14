#pragma once
#include "../ACommand.hpp"

class List : public ACommand
{
public:
    List();
    List(Model *t_model);
    ~List();

    ResponseBody run(int t_fd, RequestBody t_request);
    RequestBody parse(const std::string &t_line);
};
