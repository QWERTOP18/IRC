#pragma once
#include "AChannelCommand.hpp"

class Part : public AChannelCommand
{
public:
    Part();
    Part(Model *t_model);
    ~Part();

    ResponseBody run(int t_fd, RequestBody t_request);
    RequestBody parse(const std::string &t_line);
};

// // Numeric Replies:
// //            ERR_NEEDMOREPARAMS              ERR_NOSUCHCHANNEL
// //            ERR_NOTONCHANNEL
// //    Examples:
// //    PART #twilight_zone             ; leave channel "#twilight_zone"
// //    PART #oz-ops,&group5            ; leave both channels "&group5" and
// //                                    "#oz-ops".
