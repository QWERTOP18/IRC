#pragma once
#include "macro.hpp"
#include "../Command/ACommand.hpp"

class Parser
{
private:
    /* data */
public:
    Parser(/* args */);
    ~Parser();

    ACommand *run(const std::string &buffer);
};
