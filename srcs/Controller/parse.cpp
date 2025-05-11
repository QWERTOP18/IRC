#include "Controller.hpp"

ACommand *Controller::parse(int t_fd, const std::string &t_buffer)
{
    DEBUG_LOG(__func__);
    std::istringstream iss(t_buffer);
    std::string command;
    iss >> command;

    if (m_Command.find(command) == m_Command.end())
    {
        return NULL;
    }
    DEBUG_LOG(__func__);

    ACommand *cmd = m_Command[command];
    cmd->setModel(m_Model);
    RequestBody request;
    request.m_fd = t_fd;
    request.m_command = command;
    request.m_nickname = m_Model->getClient(t_fd)->getNickname();
    request.m_content = t_buffer.substr(command.length() + 1);

    cmd->setRequest(request);
    LOG("Command parsed: " + command);
    return cmd;
}
