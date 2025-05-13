#pragma once
#include "ACommand.hpp"

class Pass : public ACommand
{
    // private:
    //     std::string m_password;

public:
    Pass();
    Pass(Model *t_model);
    ~Pass();

    // void setPassword(const std::string &t_password) { m_password = t_password; }
    ResponseBody run(int t_fd, RequestBody t_request);
    RequestBody parse(const std::string &t_line);
};
