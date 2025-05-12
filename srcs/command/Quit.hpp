#pragma once
#include "ABuiltin.hpp"

class Quit : public ABuiltin
{
public:
    Quit();
    Quit(Model *t_model);
    ~Quit();

    ResponseBody run(int t_fd, RequestBody t_request);
    RequestBody parse(const std::string &t_line);
};
