#include "ResponseBody.hpp"

ResponseBody::ResponseBody(int t_status, const std::string &t_content)
    : IBody()
{
    m_status = t_status;
    m_content = t_content;
    m_hostname = "localhost";
}
