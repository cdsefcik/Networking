#if 0 //Used for commenting out with large blocks of code.
#include <boost/asio.hpp>
#include <iostream>
#include <memory>
#include <cstdlib>

using boost::asio::ip::tcp;

class Session : public std::enable_shared_from_this<Session> {
public:
    Session(tcp::socket socket)
        : socket_(std::move(socket)) {
    }

    void Start() {
        DoRead();
    }

private:
    void DoRead() {
        auto self(shared_from_this());
        socket_.async_read_some(
            boost::asio::buffer(data_, max_length),
            [this, self](boost::system::error_code ec, std::size_t length) {
                if (!ec) {
                    DoWrite(length);
                }
            });
    }

    void DoWrite(std::size_t length) {
        auto self(shared_from_this());
        boost::asio::async_write(
            socket_,
            boost::asio::buffer(data_, length),
            [this, self](boost::system::error_code ec, std::size_t /*length*/) {
                if (!ec) {
                    DoRead();
                }
            });
    }

    tcp::socket socket_;
    enum { max_length = 1024 };
    char data_[max_length];
};

class Server {
public:
    Server(boost::asio::io_context& io_context, short port)
        : acceptor_(io_context, tcp::endpoint(tcp::v4(), port)) {
        DoAccept();
    }

private:
    void DoAccept() {
        acceptor_.async_accept([this](boost::system::error_code ec, tcp::socket socket) {
            if (!ec) {
                std::make_shared<Session>(std::move(socket))->Start();
            }
            DoAccept();
            });
    }

    tcp::acceptor acceptor_;
};

int main(int argc, char* argv[]) {
    try {
        if (argc != 2) {
            std::cerr << "Usage: NetworkingProject <port>\n";
            return 1;
        }

        boost::asio::io_context io_context;
        short port = static_cast<short>(std::atoi(argv[1]));

        Server s(io_context, port);
        io_context.run();

    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}

#endif //Used for commenting out with large blocks of code.