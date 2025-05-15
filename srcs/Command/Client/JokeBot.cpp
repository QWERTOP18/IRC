#include "JokeBot.hpp"

JokeBot::JokeBot()
{
    DEBUG_FUNC();
}

JokeBot::~JokeBot()
{
    DEBUG_FUNC();
}

ResponseBody JokeBot::run(int t_fd, RequestBody t_request)
{
    DEBUG_FUNC();
    (void)t_fd;
    (void)t_request;

    return ResponseBody(RPL_NONE, fetchJoke());
}

RequestBody JokeBot::parse(const std::string &t_line)
{
    DEBUG_FUNC();
    RequestBody request;
    std::istringstream iss(t_line);
    iss >> request.m_command; // JokeBot

    return request;
}

const std::string JokeBot::fetchJoke()
{
    static const std::string jokes_array[] = {
        "Why do programmers hate nature? It has too many bugs.",
        "There are only 10 types of people in the world: those who understand binary and those who don't.",
        "Debugging is like being the detective in a crime movie where you are also the murderer.",
        "In order to understand recursion, one must first understand recursion."
    };

    static const int num_jokes = sizeof(jokes_array) / sizeof(jokes_array[0]);
    return jokes_array[rand() % num_jokes];
}
