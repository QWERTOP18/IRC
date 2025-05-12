#pragma once
#include "ACommand.hpp"

class Who : public ACommand
{
public:
    Who();
    Who(Model *t_model);
    ~Who();

    ResponseBody run(RequestBody t_request);
    RequestBody parse(const std::string &t_line);
};
