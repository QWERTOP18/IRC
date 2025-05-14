#pragma once
#include "ACommandBase.hpp"

class ABuiltin : virtual public ACommandBase
{
public:
    ResponseBody start(int t_fd, const std::string &t_line);
};
