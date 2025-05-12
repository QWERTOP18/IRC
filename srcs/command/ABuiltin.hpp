#include "ACommandBase.hpp"

class ABuiltin : virtual public ACommandBase
{
public:
    void start(int t_fd, const std::string &t_line);
};
