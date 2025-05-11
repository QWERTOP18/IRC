#pragma once
#include "macro.hpp"

class Model; // Forward declaration

class ACommand
{
protected:
    Model *m_Model;
    RequestBody m_request;

public:
    ACommand();
    void setModel(Model *t_model);
    void setRequest(const RequestBody &t_request) { m_request = t_request; }
    virtual ~ACommand();
    virtual ResponseBody run() = 0;
};
