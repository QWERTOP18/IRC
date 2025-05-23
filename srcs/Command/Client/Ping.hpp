#pragma once
#include "AClientCommand.hpp"

class Ping : public AClientCommand
{

public:
    Ping();
    Ping(Model *t_model);
    ~Ping();

    ResponseBody run(int t_fd, RequestBody t_request);
    RequestBody parse(const std::string &t_line);
};
