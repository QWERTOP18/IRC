#pragma once
#include "ACommand.hpp"

class Kick : public ACommand
{
public:
    Kick();
    ~Kick();

    ResponseBody run();
};
