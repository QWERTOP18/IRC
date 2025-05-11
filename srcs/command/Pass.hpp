#pragma once
#include "ACommand.hpp"

class Pass : public ACommand
{
public:
    Pass();
    ~Pass();

    ResponseBody run();
};
