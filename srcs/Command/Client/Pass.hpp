#pragma once
#include "AClientCommand.hpp"

class Pass : public AClientCommand
{

public:
    Pass();
    Pass(Model *t_model);
    ~Pass();

    ResponseBody run(int t_fd, RequestBody t_request);
    RequestBody parse(const std::string &t_line);
};
