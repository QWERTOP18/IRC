#pragma once

#include "macro.hpp"
// #include "Parser.hpp"

#include "../Command/Channel/Part.hpp"
#include "../Command/Channel/Topic.hpp"
#include "../Command/Channel/Mode.hpp"
#include "../Command/Channel/Invite.hpp"
#include "../Command/Channel/Kick.hpp"
#include "../Command/Client/Ping.hpp"
#include "../Command/Client/Pong.hpp"

#include "../Command/Other/Join.hpp"
#include "../Command/Other/Notice.hpp"
#include "../Command/Other/PrivMsg.hpp"
#include "../Command/Other/Who.hpp"

#include "../Command/Client/Pass.hpp"
#include "../Command/Client/Nick.hpp"
#include "../Command/Client/User.hpp"
#include "../Command/Client/Quit.hpp"
#include "../Command/Client/JokeBot.hpp"

#include "../Command/Client/AClientCommand.hpp"
#include "../Command/Channel/AChannelCommand.hpp"
#include "../Command/Other/ACommand.hpp"
#include "../Command/ACommandBase.hpp"
class Controller
{
private:
    std::map<std::string, ACommand *> m_Command;
    std::map<std::string, AClientCommand *> m_ClientCommand;
    std::map<std::string, AChannelCommand *> m_ChannelCommand;

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
