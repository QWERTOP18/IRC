#pragma once
#include "IBody.hpp"

class ResponseBody : public virtual IBody
{
private:
public:
    std::string m_hostname;
    int m_status;
};
