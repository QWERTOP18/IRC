#pragma once
#include "ACommand.hpp"

class Nick : public ACommand
{
public:
    Nick();
    Nick(Model *t_model);
    ~Nick();

    ResponseBody run(int t_fd, RequestBody t_request);
    RequestBody parse(const std::string &t_line);
};

// // Numeric Replies:
// //            ERR_NONICKNAMEGIVEN             ERR_ERRONEUSNICKNAME
// //            ERR_NICKNAMEINUSE               ERR_NICKCOLLISION
// //    Example:
// //    NICK Wiz                        ; Introducing new nick "Wiz".
// //    :WiZ NICK Kilroy                ; WiZ changed his nickname to Kilroy.
