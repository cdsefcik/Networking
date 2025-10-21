#if 0 //Used for commenting out with large blocks of code.
#define _WIN32_WINNT 0x0A00
#include <iostream>
#include <string>
#include <boost/asio.hpp>

/*
To run this program type NetworkingClient.exe 127.0.0.1 8080 in the command line. 
*/

using boost::asio::ip::tcp;

int main(int argc, char* argv[]) {
    try {
        if (argc != 3) {
            std::cerr << "Usage: " << argv[0] << " <host> <port>\n";
            return 1;
        }

        boost::asio::io_context io_context;

        tcp::resolver resolver(io_context);
        auto endpoints = resolver.resolve(argv[1], argv[2]);

        tcp::socket socket(io_context);
        boost::asio::connect(socket, endpoints);

        std::cout << "Connected to server at " << argv[1] << ":" << argv[2] << "\n";
        std::cout << "Type messages to send (Ctrl+C to exit):\n";

        for (;;) {
            std::string message;
            std::getline(std::cin, message);

            if (message.empty())
                continue;

            message += "\n";
            boost::asio::write(socket, boost::asio::buffer(message));

            char reply[1024];
            boost::system::error_code error;
            size_t reply_length = socket.read_some(boost::asio::buffer(reply), error);

            if (error == boost::asio::error::eof) {
                std::cout << "Connection closed by server.\n";
                break;
            }
            else if (error) {
                throw boost::system::system_error(error);
            }

            std::cout << "Server replied: " << std::string(reply, reply_length);
        }
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}
#endif //Used for commenting out with large blocks of code.