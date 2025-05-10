
namespace Err
{
    namespace Port
    {

        static const char *NOT_NUMERIC = "Port must be a numeric value";
        static const char *OUT_OF_RANGE = "Port must be between 6660 and 6669";
    }
    namespace Password
    {
        static const char *TOO_SHORT = "Password must be at least 4 characters long";
        static const char *LOWERCASE_MISSING = "Password must include lowercase";
        static const char *UPPERCASE_MISSING = "Password must include uppercase";
    }

    // exception Classにしてもいいかも
    namespace Socket
    {
        static const char *OPEN_FAIL = "failed to open socket";
        static const char *SETOPT_FAIL = "failed to set socket options";
        static const char *NONBLOCK_FAIL = "failed to set non-blocking mode";
        static const char *BIND_FAIL = "failed to bind socket";
        static const char *LISTEN_FAIL = "failed to listen on socket";
        static const char *ACCEPT_FAIL = "failed to accept connection";
        static const char *RECV_FAIL = "failed to read from socket";
        static const char *GETNAME_FAIL = "failed to get hostname";
        static const char *POLL_FAIL = "failed to poll file descriptor";
    }
    namespace Client
    {
        static const char *ACCEPT_FAIL = "failed to accept client connection";
        static const char *SEND_FAIL = "failed to send data to client";
        static const char *RECV_FAIL = "failed to receive data from client";
    }

}
