#pragma once

#include "macro.hpp"
// #include "Parser.hpp"
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
    Model *m_Model;
    std::string getCmdName(const std::string &buffer);
    std::string readRequest(int fd); // ⚠️bufferに追加
    void sendResponse(int fd, const ResponseBody &response);

public:
    Controller(Model *model);
    ~Controller();
    void addClient(int fd);
    void removeClient(int fd);
    void handleRequest(int fd);
};
