#pragma once
#include "ACommand.hpp"

class Who : public ACommand
{
public:
    Who();
    ~Who();

    ResponseBody run();
};
