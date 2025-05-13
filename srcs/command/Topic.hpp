#pragma once
#include "ACommand.hpp"

class Topic : public ACommand
{
public:
    Topic();
    Topic(Model *t_model);
    ~Topic();

    ResponseBody run(int t_fd, RequestBody t_request);
    RequestBody parse(const std::string &t_line);
};

// 4.2.4 Topic message
//       Command: TOPIC
//    Parameters: <channel> [<topic>]
//    The TOPIC message is used to change or view the topic of a channel.
//    The topic for channel <channel> is returned if there is no <topic>
//    given.  If the <topic> parameter is present, the topic for that
//    channel will be changed, if the channel modes permit this action.
//    Numeric Replies:
//            ERR_NEEDMOREPARAMS              ERR_NOTONCHANNEL
//            RPL_NOTOPIC                     RPL_TOPIC
//            ERR_CHANOPRIVSNEEDED
// Oikarinen & Reed                                               [Page 23]
// RFC 1459              Internet Relay Chat Protocol              May 1993
//    Examples:
//    :Wiz TOPIC #test :New topic     ;User Wiz setting the topic.
//    TOPIC #test :another topic      ;set the topic on #test to "another
//                                    topic".
//    TOPIC #test                     ; check the topic for #test.