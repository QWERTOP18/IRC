#pragma once
#include "ACommand.hpp"

class Notice : public ACommand
{
public:
    Notice();
    Notice(Model *t_model);
    ~Notice();

    ResponseBody run(int t_fd, RequestBody t_request);
    RequestBody parse(const std::string &t_line);
};
