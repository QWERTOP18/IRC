#pragma once
#include "../ACommandBase.hpp"
#include "../../Model/Model.hpp"

class ACommand : virtual public ACommandBase
{
public:
    ResponseBody start(int t_fd, const std::string &t_line);
};
