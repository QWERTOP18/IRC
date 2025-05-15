#pragma once
#include "../ACommandBase.hpp"
#include "../../Model/Model.hpp"

class AChannelCommand : virtual public ACommandBase
{
protected:
    // bool checkPrivilege(int t_fd, int t_channel_id, MODE t_mode) const;
    // MODE m_privilege;

public:
    ResponseBody start(int t_fd, const std::string &t_line);
};
