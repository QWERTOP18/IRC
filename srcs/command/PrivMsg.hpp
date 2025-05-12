#pragma once
#include "ACommand.hpp"

class PrivMsg : public ACommand
{
public:
    PrivMsg();
    ~PrivMsg();

    ResponseBody run(RequestBody t_request);
    RequestBody parse(const std::string &t_line);
};
