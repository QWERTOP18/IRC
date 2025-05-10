#include "../ACommand.hpp"

class Pass : public ACommand
{
public:
    Pass();
    ~Pass();

    void execute();
};