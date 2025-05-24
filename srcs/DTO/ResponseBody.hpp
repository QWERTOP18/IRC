#pragma once
#include "IBody.hpp"

class ResponseBody : public virtual IBody
{
private:
public:
    std::string m_hostname;

    ResponseBody(int t_status = 0, const std::string &t_content = "");
};
