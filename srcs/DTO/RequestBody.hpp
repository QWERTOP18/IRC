#pragma once
#include "IBody.hpp"

class RequestBody : public IBody
{
public:
    RequestBody() : IBody() { m_status = 0; };
    RequestBody(int t_status) : IBody() { m_status = t_status; };

    ~RequestBody() {};
};
