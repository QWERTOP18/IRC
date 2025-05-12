#include "Controller.hpp"

std::string Controller::getCmdName(const std::string &t_buffer)
{
    DEBUG_LOG();
    std::istringstream iss(t_buffer);
    std::string command;
    iss >> command;

    return command;
}

std::string Controller::readRequest(int fd)
{
    DEBUG_LOG();
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
    DEBUG_LOG();
    std::string message = response.m_command + " " + to_string(response.m_status) + " " + response.m_content + "\r\n";
    send(fd, message.c_str(), message.size(), 0);
}
