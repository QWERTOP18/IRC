#pragma once

#include "macro.hpp"
#include "Parser.hpp"

#include "../Command/ClientOperator/Pass.hpp"
#include "../Command/ClientOperator/Nick.hpp"
#include "../Command/ClientOperator/User.hpp"
#include "../Command/ChannelOperator/Join.hpp"
#include "../Command/ChannelOperator/Part.hpp"
#include "../Command/ClientOperator/Quit.hpp"

// #include "../Command/ClientOperator/Pong.hpp"
// #include "../Command/ClientOperator/Ping.hpp"
#include "../Command/ChannelOperator/Mode.hpp"
#include "../Command/ChannelOperator/Topic.hpp"

#include "../Command/ChannelOperator/Kick.hpp"
#include "../Command/ChannelOperator/Invite.hpp"

#include "../Command/PrivMsg.hpp"
// #include "../Command/Who.hpp"

#include <map>
#include "../Command/ACommand.hpp"
class Controller
{
private:
    std::map<std::string, ACommand *> m_Command;

public:
    Controller();
    ~Controller();
};

Controller::Controller()
{
    m_Command["PASS"] = new Pass();
    m_Command["NICK"] = new Nick();
    m_Command["USER"] = new User();
    m_Command["JOIN"] = new Join();
    m_Command["PART"] = new Part();
    m_Command["PRIVMSG"] = new PrivMsg();
    m_Command["PONG"] = new Pong();
    m_Command["PING"] = new Ping();
    m_Command["QUIT"] = new Quit();
}

Controller::~Controller()
{
}
