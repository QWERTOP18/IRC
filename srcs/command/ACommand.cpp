#include "ACommand.hpp"

ACommand::ACommand()
{
    DEBUG_LOG(__func__);
}

ACommand::~ACommand()
{
    DEBUG_LOG(__func__);
}

void ACommand::setModel(Model *t_model)
{
    m_Model = t_model;
}
