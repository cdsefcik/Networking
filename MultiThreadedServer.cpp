#if 0 //Used for commenting out with large blocks of code.
#define _WIN32_WINNT 0x0A00
#include <iostream>
#include <thread>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

void session(tcp::socket sock) {
    try {
        char data[1024];
        for (;;) {
            boost::system::error_code error;
            size_t length = sock.read_some(boost::asio::buffer(data), error);
            if (error == boost::asio::error::eof)
                break;  // connection closed cleanly by peer
            else if (error)
                throw boost::system::system_error(error); // some other error

            boost::asio::write(sock, boost::asio::buffer(data, length));
        }
    }
    catch (std::exception& e) {
        std::cerr << "Exception in thread: " << e.what() << "\n";
    }
}

void server(boost::asio::io_context& io_context, short port) {
    tcp::acceptor a(io_context, tcp::endpoint(tcp::v4(), port));
    for (;;) {
        tcp::socket sock(io_context);
        a.accept(sock);
        std::thread(session, std::move(sock)).detach();
    }
}

int main(int argc, char* argv[]) {
    try {
        if (argc != 2) {
            std::cerr << "Usage: " << argv[0] << " <port>\n";
            return 1;
        }

        boost::asio::io_context io_context;
        short port = static_cast<short>(std::atoi(argv[1]));
        server(io_context, port);
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }
    return 0;
}

#endif //Used for commenting out with large blocks of code.