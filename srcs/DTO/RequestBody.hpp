#pragma once
#include "IBody.hpp"

class RequestBody : public IBody
{
public:
    std::string m_target_channel;
    std::string m_target_nickname;
    RequestBody() : IBody() {};
    ~RequestBody() {};
};
