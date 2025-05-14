#pragma once
#include "../ACommand.hpp"

class Who : public ACommand
{
public:
    Who();
    Who(Model *t_model);
    ~Who();

    ResponseBody run(int t_fd, RequestBody t_request);
    RequestBody parse(const std::string &t_line);
};

// Numeric Replies:
//            ERR_NOSUCHSERVER
//            RPL_WHOREPLY                    RPL_ENDOFWHO
//    Examples:
//    WHO *.fi                        ; List all users who match against
//                                    "*.fi".
//    WHO jto* o                      ; List all users with a match against
//                                    "jto*" if they are an operator.
