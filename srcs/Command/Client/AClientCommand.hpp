#pragma once
#include "../ACommandBase.hpp"
#include "../../Model/Model.hpp"

class AClientCommand : virtual public ACommandBase
{
public:
    ResponseBody start(int t_fd, const std::string &t_line);
};
