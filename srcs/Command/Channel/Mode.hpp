#pragma once
#include "../ACommand.hpp"

class Mode : public ACommand
{
public:
    Mode();
    Mode(Model *t_model);
    ~Mode();

    ResponseBody run(int t_fd, RequestBody t_request);
    RequestBody parse(const std::string &t_line);
};
