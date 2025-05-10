#pragma once

#include "macro.hpp"
#include "Parser.hpp"
#include "../Model/Model.hpp"

#include "../Command/Pass.hpp"
#include "../Command/Nick.hpp"
#include "../Command/User.hpp"
#include "../Command/Join.hpp"
#include "../Command/Part.hpp"
#include "../Command/PrivMsg.hpp"
#include "../Command/Quit.hpp"
#include "../Command/Mode.hpp"
#include "../Command/Topic.hpp"
#include "../Command/Kick.hpp"
#include "../Command/Invite.hpp"
#include "../Command/Who.hpp"
#include "../Command/List.hpp"

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
