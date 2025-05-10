#pragma once
#include "macro.hpp"
#include "../Command/ACommand.hpp"

class Parser
{
private:
    /* data */
public:
    Parser();
    ~Parser();

    ACommand *run(std::string &buffer);
};
