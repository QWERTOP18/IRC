#pragma once
#include "../ABuiltin.hpp"

class User : public ABuiltin
{

public:
    User();
    User(Model *t_model);
    ~User();

    ResponseBody run(int t_fd, RequestBody t_request);
    RequestBody parse(const std::string &t_line);
};
