/*
#include <boost/asio.hpp>
#include <iostream>

//This is the new version.

int main() {
    try {
        boost::asio::io_context io_context;

        boost::asio::ip::tcp::resolver resolver(io_context);
        // Newer API: call resolve(host, service) directly
        boost::asio::ip::tcp::resolver::results_type results = resolver.resolve("www.google.com", "80");

        for (const auto& entry : results) {
            boost::asio::ip::tcp::endpoint endpoint = entry.endpoint();
            std::cout << endpoint.address().to_string() << ":" << endpoint.port() << std::endl;
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << '\n';
        return 1;
    }
    return 0;
}

*/