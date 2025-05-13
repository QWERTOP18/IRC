#include "Controller.hpp"

Controller::Controller(Model *model) : m_Model(model)
{
    m_Builtin["QUIT"] = new Quit(model);
    m_Command["PASS"] = new Pass(model);

    m_Command["NICK"] = new Nick(model);
    m_Command["USER"] = new User(model);
    m_Command["JOIN"] = new Join(model);
    m_Command["PART"] = new Part(model);
    m_Command["PRIVMSG"] = new PrivMsg(model);
    // m_Command["MODE"] = new Mode(model);
    m_Command["TOPIC"] = new Topic(model);
    // m_Command["KICK"] = new Kick(model);
    m_Command["INVITE"] = new Invite(model);
    m_Command["WHO"] = new Who(model);
}

Controller::~Controller()
{
    for (std::map<std::string, ACommand *>::iterator it = m_Command.begin(); it != m_Command.end(); ++it)
    {
        delete it->second;
    }
    m_Command.clear();
}

void Controller::addClient(int fd)
{
    m_Model->addClient(fd);
}

void Controller::removeClient(int fd)
{
    m_Model->removeClient(fd);
}

void Controller::handleRequest(int t_fd)
{
    DEBUG_LOG();
    std::string line = readRequest(t_fd);
    if (line.empty())
        return;
    ACommandBase *cmdBase = getCmdBase(line);
    if (cmdBase == NULL)
    {
        LOG("Command not found: " + line);
        return;
    }
    // Quitなどの出力を返さないコマンドはBuiltinとして処理
    if (ABuiltin *cmd = dynamic_cast<ABuiltin *>(cmdBase))
    {
        cmd->start(t_fd, line);
        return;
    }
    if (ACommand *cmd = dynamic_cast<ACommand *>(cmdBase))
    {
        ResponseBody response = cmd->start(t_fd, line);
        sendResponse(t_fd, response);
        return;
    }
    LOG("Command not found: " + line);
}
