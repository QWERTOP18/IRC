#include "Model.hpp"

const std::string Model::getModelInfo() const
{
    std::stringstream ss;
    ss << "----------------------" << std::endl;
    ss << "Model Info: " << std::endl;
    ss << "Clients: " << m_Client.size() << std::endl;
    ss << "Channels: " << m_Channel.size() << std::endl;
    ss << "Hub: " << m_Hub.size() << std::endl;
    ss << "--------------------------------" << std::endl;

    return ss.str();
}