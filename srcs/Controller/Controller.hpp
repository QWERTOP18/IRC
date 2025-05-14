#pragma once

#include "macro.hpp"
// #include "Parser.hpp"

#include "../Command/Channel/Join.hpp"
#include "../Command/Channel/Part.hpp"
#include "../Command/Channel/Topic.hpp"
#include "../Command/Channel/Mode.hpp"
#include "../Command/Channel/Invite.hpp"
#include "../Command/Channel/List.hpp"
#include "../Command/Channel/Kick.hpp"
#include "../Command/Other/PrivMsg.hpp"
#include "../Command/Other/Who.hpp"
#include "../Command/Builtin/Pass.hpp"
#include "../Command/Builtin/Nick.hpp"
#include "../Command/Builtin/User.hpp"
#include "../Command/Builtin/Quit.hpp"

#include <map>
#include "../Command/ACommand.hpp"
class Controller
{
private:
    std::map<std::string, ACommand *> m_Command;
    std::map<std::string, ABuiltin *> m_Builtin;

    Model *m_Model;
    std::string getCmdName(const std::string &buffer);
    ACommandBase *getCmdBase(const std::string &t_line);
    std::string readRequest(int fd); // ⚠️bufferに追加
    void sendResponse(int fd, const ResponseBody &response);

public:
    Controller(Model *model);
    ~Controller();
    void addClient(int fd);
    void removeClient(int fd);
    void handleRequest(int fd);
};
