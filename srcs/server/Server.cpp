#include "Server.hpp"

Server::Server(const std::string &t_port, const std::string &t_password)
{
    setPort(t_port);
    setPassword(t_password);
    setSocket();
}

Server::~Server()
{
}

void Server::start()
{
    std::cout << "Server started on port " << m_port << std::endl;
}
