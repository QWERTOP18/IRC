#include "Controller.hpp"

Controller::Controller(Model *model) : m_Model(model)
{
    // m_Command["PASS"] = new Pass();
    // m_Command["NICK"] = new Nick();
    // m_Command["USER"] = new User();
    // m_Command["JOIN"] = new Join();
    // m_Command["PART"] = new Part();
    // m_Command["PRIVMSG"] = new PrivMsg();
    // m_Command["QUIT"] = new Quit();
    // m_Command["MODE"] = new Mode();
    // m_Command["TOPIC"] = new Topic();
    // m_Command["KICK"] = new Kick();
    // m_Command["INVITE"] = new Invite();
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
    std::string command = getCmdName(line);
    if (m_Command.find(command) == m_Command.end())
    {
        LOG("Unknown command: " + command);
        return;
    }
    ACommand *cmd = m_Command[command];
    ResponseBody response = cmd->start(t_fd, line);

    // 👍QUITの時は送らないように
    sendResponse(t_fd, response);
}
