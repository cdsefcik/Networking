/**
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <iostream>
#include <string>

namespace http = boost::beast::http;
namespace net = boost::asio;
using tcp = net::ip::tcp;

int main() {
    try {
        auto const host = "example.com";
        auto const port = "80";
        auto const target = "/index.html";
        int version = 11;

        net::io_context ioc;

        tcp::resolver resolver(ioc);
        auto const results = resolver.resolve(host, port); //resolver.resolve() converts "example.com" and port "80" into one or more TCP endpoints (IP addresses).

        tcp::socket socket(ioc);
        net::connect(socket, results);   // simpler overload

        // Set up HTTP request
        http::request<http::string_body> req{ http::verb::get, target, version };
        req.set(http::field::host, host);
        req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);

        // Send request
        http::write(socket, req);

        // Receive response
        boost::beast::flat_buffer buffer;
        http::response<http::dynamic_body> res;
        http::read(socket, buffer, res);

        // Print result
        std::cout << res << std::endl;

        // Gracefully close socket
        boost::system::error_code ec;
        socket.shutdown(tcp::socket::shutdown_both, ec);
        if (ec && ec != boost::system::errc::not_connected)
            throw boost::system::system_error(ec);
    }
    catch (std::exception const& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

**/