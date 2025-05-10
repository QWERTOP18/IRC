#pragma once
#include "macro.hpp"

class ACommand
{
private:
public:
    ACommand();
    virtual ~ACommand();
    virtual void execute() = 0;
};
