#pragma once
#include "ACommand.hpp"

class PrivMsg : public ACommand
{
public:
    PrivMsg();
    ~PrivMsg();

    ResponseBody run();
};
