#include "Controller.hpp"

Controller::Controller(Model *model) : m_Model(model)
{
    m_Command["PASS"] = new Pass();
    // m_Command["NICK"] = new Nick();
    // m_Command["USER"] = new User();
    m_Command["JOIN"] = new Join();
    // m_Command["PART"] = new Part();
    // m_Command["PRIVMSG"] = new PrivMsg();
    // m_Command["QUIT"] = new Quit();
    // m_Command["MODE"] = new Mode();
    // m_Command["TOPIC"] = new Topic();
    // m_Command["KICK"] = new Kick();
    // m_Command["INVITE"] = new Invite();
    // m_Command["WHO"] = new Who();
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
    std::string &buffer = m_Model->getClient(fd)->getBuffer();
    char buf[1024];
    ssize_t bytesRead = recv(fd, buf, sizeof(buf) - 1, 0);
    if (bytesRead <= 0)
    {
        removeClient(fd);
        return;
    }
    buf[bytesRead] = '\0';
    buffer += buf;
    DEBUG_LOG("Received: " + buffer);
    buffer.erase(0, buffer.find_first_not_of("\r\n"));
    // if (buffer.find("\r\n") == std::string::npos)
    //     return;
    // response.m_command = buffer.substr(0, buffer.find("\r\n"));
    // buffer.erase(0, buffer.find("\r\n") + 2);
    // if (response.m_command.empty())
    //     return;
    // if (response.m_command[0] == ':')
    // {
    //     response.m_command = response.m_command.substr(response.m_command.find(' ') + 1);
    // }
    // if (response.m_command.find(' ') != std::string::npos)
    // {
    //     response.m_command = response.m_command.substr(0, response.m_command.find(' '));
    // }
    // if (m_Command.find(response.m_command) == m_Command.end())
    // {
    //     response.m_status = ERR_UNKNOWNCOMMAND;
    //     response.m_content = "Unknown command: " + response.m_command;
    // }
    // else
    // {

    //     ACommand *command = m_Command[response.m_command];

    //     ResponseBody response = command->run();

    //     command->setModel(m_Model);
    //     response = command->run();
    // }
    // LOG("Response: " + std::to_string(response.m_status) + " " + response.m_content);
    // send(fd, response.m_content.c_str(), response.m_content.size(), 0);
}
