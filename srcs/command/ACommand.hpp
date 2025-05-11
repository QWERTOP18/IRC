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
    virtual ~ACommand();
    virtual ResponseBody run() = 0;
};
