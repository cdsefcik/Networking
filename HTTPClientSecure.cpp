/*
#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/core.hpp>
#include <boost/beast/version.hpp>
#include <iostream>

namespace http = boost::beast::http;
namespace net = boost::asio;
namespace ssl = net::ssl;
using tcp = net::ip::tcp;

int main() {
    try {
        auto const host = "example.com";
        auto const port = "443";
        auto const target = "/index.html";
        int version = 11;

        net::io_context ioc;

        ssl::context ctx{ ssl::context::tlsv12_client };
        ctx.set_default_verify_paths();

        tcp::resolver resolver{ ioc };
        auto const results = resolver.resolve(host, port);

        ssl::stream<tcp::socket> stream{ ioc, ctx };

        // Connect lowest layer (TCP)
        net::connect(stream.next_layer(), results);

        // Perform SSL handshake
        stream.handshake(ssl::stream_base::client);

        // Set up HTTP request
        http::request<http::string_body> req{ http::verb::get, target, version };
        req.set(http::field::host, host);
        req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);

        // Send request over TLS stream
        http::write(stream, req);

        // Receive response
        boost::beast::flat_buffer buffer;
        http::response<http::dynamic_body> res;
        http::read(stream, buffer, res);

        // Print result
        std::cout << res << std::endl;

        // Gracefully shut down TLS
        boost::system::error_code ec;
        stream.shutdown(ec);
        if (ec == net::error::eof) {
            ec.assign(0, ec.category()); // Ignore EOF
        }
        if (ec) throw boost::system::system_error(ec);
    }
    catch (std::exception const& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
*/


