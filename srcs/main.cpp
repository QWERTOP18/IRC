#include "server/Server.hpp"

int main(int argc, char **argv)
{
    try
    {
        if (argc != 3)
            throw std::invalid_argument("Usage: ./IRC <port> <password>");
        Server server(argv[1], argv[2]);
        server.start();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return EXIT_FAILURE;
    }
}
