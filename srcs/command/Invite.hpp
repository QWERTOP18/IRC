#pragma once
#include "ACommand.hpp"

class Invite : public ACommand
{
public:
    Invite();
    ~Invite();

    ResponseBody start();
    void parse(int t_fd, const std::string &t_buffer);
};

// 4.2.7 Invite message

//       Command: INVITE
//    Parameters: <nickname> <channel>

//    The INVITE message is used to invite users to a channel.  The
//    parameter <nickname> is the nickname of the person to be invited to
//    the target channel <channel>.  There is no requirement that the
//    channel the target user is being invited to must exist or be a valid
//    channel.  To invite a user to a channel which is invite only (MODE
//    +i), the client sending the invite must be recognised as being a
//    channel operator on the given channel.

//    Numeric Replies:

//            ERR_NEEDMOREPARAMS              ERR_NOSUCHNICK
//            ERR_NOTONCHANNEL                ERR_USERONCHANNEL
//            ERR_CHANOPRIVSNEEDED
//            RPL_INVITING                    RPL_AWAY

//    Examples:

//    :Angel INVITE Wiz #Dust         ; User Angel inviting WiZ to channel
//                                    #Dust

//    INVITE Wiz #Twilight_Zone       ; Command to invite WiZ to
//                                    #Twilight_zone
