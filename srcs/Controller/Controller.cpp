#include "Controller.hpp"

Controller::Controller(Model *model) : m_Model(model)
{
    m_Command["PASS"] = new Pass();
    m_Command["NICK"] = new Nick();
    // m_Command["USER"] = new User();
    m_Command["JOIN"] = new Join();
    m_Command["PART"] = new Part();
    // m_Command["PRIVMSG"] = new PrivMsg();
    m_Command["QUIT"] = new Quit();
    // m_Command["MODE"] = new Mode();
    m_Command["TOPIC"] = new Topic();
    m_Command["KICK"] = new Kick();
    // m_Command["INVITE"] = new Invite();
    m_Command["WHO"] = new Who();
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

void Controller::handleRequest(int fd)
{
    DEBUG_LOG(__func__);
    ResponseBody response;
    RequestBody request;

    std::string &buffer = m_Model->getClient(fd)->getBuffer();
    char buf[1024];
    ssize_t bytesRead = recv(fd, buf, sizeof(buf) - 1, 0);
    if (bytesRead <= 0 and (errno != EWOULDBLOCK))
    {
        return;
    }
    buf[bytesRead] = '\0';
    buffer += buf;
    if (buffer.find("\n") == std::string::npos)
        return;
    DEBUG_LOG("Received: " + buffer);
    send(fd, buffer.c_str(), strlen(buffer.c_str()), 0);
    ACommand *cmd = parse(fd, buffer);

    // if (m_Command.find(response.m_command) == m_Command.end())
    if (cmd == NULL)
    {
        response.m_status = ERR_UNKNOWNCOMMAND;
        response.m_content = "Unknown command: " + response.m_command;
        send(fd, response.m_content.c_str(), strlen(response.m_content.c_str()), 0); // delete later
        buffer.erase(0, buffer.find("\n") + 1);
        return;
    }
    DEBUG_LOG("Command found: " + response.m_command);

    response = cmd->run();
    response.m_command = buffer.substr(0, buffer.find("\n"));
    buffer.erase(0, buffer.find("\n") + 1);
}
