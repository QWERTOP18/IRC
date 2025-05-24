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
    // std::string &buffer = m_Model->getClient(fd)->getBuffer();
    // char buf[1024];
    // ssize_t bytesRead = recv(fd, buf, sizeof(buf) - 1, 0);
    // // linux
    // if (bytesRead <= 0)
    // {
    //     m_Model->removeClient(fd);
    //     LOG("Client " + to_string(fd) + " disconnected");
    //     return "";
    // }
    // buf[bytesRead] = '\0';
    // buffer += buf;

    // std::cout << "buffer: " << buffer << std::endl;
    // if (buffer.find("\n") == std::string::npos)
    //     return "";
    // DEBUG_LOG("Received: " + buffer);

    // std::string line = buffer.substr(0, buffer.find("\n"));
    // buffer.erase(0, buffer.find("\n") + 1);
    // return line;
    std::string message;

    char buffer[100];
    memset(buffer, 0, 100);

    while (!strstr(buffer, "\n"))
    {
        memset(buffer, 0, 100);

        if ((recv(fd, buffer, 100, 0) < 0) and (errno != EWOULDBLOCK))
            throw std::runtime_error(Err::Recv::FAILED);

        message.append(buffer);
    }
    std::cout << "message: " << message << std::endl;
    return message;
}

void Controller::sendResponse(int fd, const ResponseBody &response)
{
    DEBUG_FUNC();

    std::string message;
    if (response.m_status == NO_REPLY)
        return;
    if (response.m_status == RPL_NOUSERS)
        message = ":" + m_Model->getClient(fd)->getClientInfo() + " :" + response.m_content + "\r\n";
    else
        message = ":" + m_Model->getClient(fd)->getClientInfo() + " " + zero_pad3(response.m_status) + " :" + response.m_content + "\r\n";

    std::cout << "response: " << response.m_status << " " << response.m_content << std::endl;
    LOG("Sending: " + message);
    send(fd, message.c_str(), message.length(), 0);
}
