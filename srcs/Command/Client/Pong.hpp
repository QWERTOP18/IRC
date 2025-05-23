#pragma once
#include "AClientCommand.hpp"

class Pong : public AClientCommand
{

public:
    Pong();
    Pong(Model *t_model);
    ~Pong();

    ResponseBody run(int t_fd, RequestBody t_request);
    RequestBody parse(const std::string &t_line);
};
