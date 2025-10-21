#if 0 //Used for commenting out with large blocks of code.
#include <boost/asio.hpp>
#include <vector>
#include <chrono>
#include <thread>
#include <iostream>

int main() {
    try {
        boost::asio::io_context io_context;
        std::vector<boost::asio::ip::tcp::socket> sockets;

        for (int i = 0; i < 10000; ++i) {
            sockets.emplace_back(io_context);
            sockets.back().connect(
                {boost::asio::ip::make_address("127.0.0.1"), 1234});
        }

        std::cout << "Opened " << sockets.size() << " connections.\n";
        std::this_thread::sleep_for(std::chrono::minutes(1));
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}

#endif //Used for commenting out with large blocks of code.