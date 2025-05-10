#pragma once
#include "ACommand.hpp"

class Quit : public ACommand
{
public:
    Quit();
    ~Quit();

    ResponseBody run(RequestBody t_request);
};
