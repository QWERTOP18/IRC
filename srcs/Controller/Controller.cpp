#include "Controller.hpp"

Controller::Controller(Model *model) : m_Model(model)
{
    m_ClientCommand["QUIT"] = new Quit(model);
    m_ClientCommand["PASS"] = new Pass(model);
    m_ClientCommand["NICK"] = new Nick(model);
    m_ClientCommand["USER"] = new User(model);
    m_ClientCommand["JOKE"] = new JokeBot();
    m_ClientCommand["PING"] = new Ping(model);

    m_Command["JOIN"] = new Join(model);
    m_Command["WHO"] = new Who(model);
    m_Command["PRIVMSG"] = new PrivMsg(model);
    m_Command["NOTICE"] = new Notice(model);

    m_ChannelCommand["PART"] = new Part(model);
    m_ChannelCommand["MODE"] = new Mode(model);
    m_ChannelCommand["TOPIC"] = new Topic(model);
    m_ChannelCommand["KICK"] = new Kick(model);
    m_ChannelCommand["INVITE"] = new Invite(model);
}

Controller::~Controller()
{
    for (std::map<std::string, ACommand *>::iterator it = m_Command.begin(); it != m_Command.end(); ++it)
    {
        delete it->second;
    }
    for (std::map<std::string, AClientCommand *>::iterator it = m_ClientCommand.begin(); it != m_ClientCommand.end(); ++it)
    {
        delete it->second;
    }
    for (std::map<std::string, AChannelCommand *>::iterator it = m_ChannelCommand.begin(); it != m_ChannelCommand.end(); ++it)
    {
        delete it->second;
    }

    m_ClientCommand.clear();
    m_ChannelCommand.clear();
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

std::string strtrim(std::string &str)
{
    str.erase(0, str.find_first_not_of(" \t\n\r\f\v"));
    str.erase(str.find_last_not_of(" \t\n\r\f\v") + 1);
    return str;
}

void Controller::handleRequest(int t_fd)
{
    std::string buffer = readRequest(t_fd);
    if (buffer.empty())
        return;

    std::stringstream ss(buffer);
    std::string line;
    while (std::getline(ss, line))
    {
        DEBUG_FUNC();
        std::cout << "line: " << line << std::endl;
        line = strtrim(line);
        ACommandBase *cmdBase = getCmdBase(line);
        if (cmdBase == NULL)
        {
            LOG("Command not found: " + line);
            sendResponse(t_fd, ResponseBody(421, "Unknown command: " + line));
            continue;
        }

        if (AClientCommand *cmd = dynamic_cast<AClientCommand *>(cmdBase))
        {
            ResponseBody response = cmd->start(t_fd, line);
            sendResponse(t_fd, response);
            continue;
        }
        if (ACommand *cmd = dynamic_cast<ACommand *>(cmdBase))
        {
            ResponseBody response = cmd->start(t_fd, line);
            sendResponse(t_fd, response);
            continue;
        }
        if (AChannelCommand *cmd = dynamic_cast<AChannelCommand *>(cmdBase))
        {
            ResponseBody response = cmd->start(t_fd, line);
            sendResponse(t_fd, response);
            continue;
        }
        LOG("Command not found: " + line);
        sendResponse(t_fd, ResponseBody(421, "Unknown command: " + line));
    }
}
