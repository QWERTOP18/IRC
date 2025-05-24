#pragma once
#include "IBody.hpp"

class RequestBody : public IBody
{

public:
    std::string m_command;
    std::string m_content2; // 2nd content
    RequestBody() : IBody() { m_status = 0; };
    RequestBody(int t_status) : IBody() { m_status = t_status; };

    ~RequestBody() {};
};
