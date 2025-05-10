#pragma once
#include "ACommand.hpp"

class Part : public ACommand
{
public:
    Part();
    ~Part();

    ResponseBody run(RequestBody t_request);
};
