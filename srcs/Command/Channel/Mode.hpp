#pragma once
#include "AChannelCommand.hpp"

class Mode : public AChannelCommand
{
public:
    Mode();
    Mode(Model *t_model);
    ~Mode();

    ResponseBody run(int t_fd, RequestBody t_request);
    RequestBody parse(const std::string &t_line);
};
