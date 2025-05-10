#pragma once

#include "macro.hpp"
#include "Parser.hpp"
#include "../Model/Model.hpp"

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
    Parser m_Parser;
    Model *m_Model;


public:
    Controller(Model *model);
    ~Controller();
    void addClient(int fd);
    void removeClient(int fd);

    
    
};

