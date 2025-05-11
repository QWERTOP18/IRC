#pragma once
#include "ACommand.hpp"

class Nick : public ACommand
{
public:
    Nick();
    ~Nick();

    ResponseBody run();
};
