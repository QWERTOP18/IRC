#pragma once
#include "macro.hpp"

class Model; // Forward declaration

class ACommand
{
protected:
    Model *m_Model;

public:
    ACommand();
    void setModel(Model *t_model);
    virtual ~ACommand();
    virtual ResponseBody run(RequestBody t_request) = 0;
};
