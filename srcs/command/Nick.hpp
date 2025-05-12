#pragma once
#include "ACommand.hpp"

class Nick : public ACommand
{
public:
    Nick();
    ~Nick();

    ResponseBody run(RequestBody t_request);
    RequestBody parse(const std::string &t_line);
};
