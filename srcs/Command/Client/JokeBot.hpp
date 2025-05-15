#pragma once
#include "AClientCommand.hpp"

class JokeBot : public AClientCommand
{
private:
    const std::string fetchJoke();

public:
    JokeBot();
    // JokeBot(Model *t_model);
    ~JokeBot();

    ResponseBody run(int t_fd, RequestBody t_request);
    RequestBody parse(const std::string &t_line);
};
