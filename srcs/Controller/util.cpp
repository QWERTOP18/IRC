#include "Controller.hpp"

std::string Controller::getCmdName(const std::string &t_buffer)
{
    // DEBUG_FUNC();
    std::istringstream iss(t_buffer);
    std::string command;
    iss >> command;
    return command;
}

ACommandBase *Controller::getCmdBase(const std::string &t_line)
{
    // DEBUG_FUNC();
    std::string cmdName = getCmdName(t_line);
    if (m_Command.find(cmdName) != m_Command.end())
        return m_Command[cmdName];
    if (m_ClientCommand.find(cmdName) != m_ClientCommand.end())
        return m_ClientCommand[cmdName];
    if (m_ChannelCommand.find(cmdName) != m_ChannelCommand.end())
        return m_ChannelCommand[cmdName];
    return NULL;
}

std::string Controller::readRequest(int fd)
{
    DEBUG_FUNC();
    std::string &buffer = m_Model->getClient(fd)->getBuffer();
    char buf[1024];
    ssize_t bytesRead = recv(fd, buf, sizeof(buf) - 1, 0);
    // if (bytesRead <= 0 && (errno != EWOULDBLOCK))
    // {
    //     return; 👍throwする
    // }
    buf[bytesRead] = '\0';
    buffer += buf;

    if (buffer.find("\n") == std::string::npos)
        return "";
    DEBUG_LOG("Received: " + buffer);

    std::string line = buffer.substr(0, buffer.find("\n"));
    buffer.erase(0, buffer.find("\n") + 1);
    return line;
}

void Controller::sendResponse(int fd, const ResponseBody &response)
{
    DEBUG_FUNC();
    if (response.m_status == NO_REPLY)
        return;
    std::string message = response.m_command + " " + to_string(response.m_status) + " " + response.m_content + "\r\n";
    send(fd, message.c_str(), message.size(), 0);
}
