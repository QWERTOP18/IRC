#pragma once
#include "ACommandBase.hpp"

class ACommand : virtual public ACommandBase
{
public:
    ResponseBody start(int t_fd, const std::string &t_line);
};
