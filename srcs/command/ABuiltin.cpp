#include "ABuiltin.hpp"

#include "../Model/Model.hpp"

void ABuiltin::start(int t_fd, const std::string &t_line)
{
    DEBUG_LOG();
    RequestBody request;

    request = parse(t_line);
    run(t_fd, request);
}
