#pragma once
#include "ACommand.hpp"

class Pass : public ACommand
{
public:
    Pass();
    ~Pass();

    ResponseBody run(RequestBody t_request);
    RequestBody parse(const std::string &t_line);
};
