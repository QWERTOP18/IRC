#pragma once
#include "ACommand.hpp"

class Topic : public ACommand
{
public:
    Topic();
    ~Topic();

    ResponseBody run();
};
