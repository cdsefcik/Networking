#if 0 //Used for commenting out with large blocks of code.
#include <boost/asio.hpp>
#include <chrono>
#include <iostream>


/*
This code is used like a TCP client to send a series of messages. The time is recorded to determine how long it takes
to send and receive a message.
*/

int main() {
    try {
        boost::asio::io_context io_context;
        boost::asio::ip::tcp::socket socket(io_context);

        auto endpoint = boost::asio::ip::tcp::endpoint(
            boost::asio::ip::make_address("127.0.0.1"), 1234);

        socket.connect(endpoint);

        auto start = std::chrono::steady_clock::now();

        for (int i = 0; i < 10000; ++i) {
            std::string message = "Hello, server!";
            boost::asio::write(socket, boost::asio::buffer(message));
        }

        auto end = std::chrono::steady_clock::now();
        std::cout << "Elapsed time: "
            << std::chrono::duration<double>(end - start).count() << "s\n";
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }
}

#endif //Used for commenting out with large blocks of code.
