#pragma once
#include "../ABuiltin.hpp"

class Pass : public ABuiltin
{

public:
    Pass();
    Pass(Model *t_model);
    ~Pass();

    ResponseBody run(int t_fd, RequestBody t_request);
    RequestBody parse(const std::string &t_line);
};
