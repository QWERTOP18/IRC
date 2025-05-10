#pragma once
#include "macro.hpp"

class Model; // Forward declaration

class ACommand
{
protected:
    Model *m_Model;

public:
    ACommand();
    virtual ~ACommand();
    virtual ResponseBody run(RequestBody t_request) = 0;
};
