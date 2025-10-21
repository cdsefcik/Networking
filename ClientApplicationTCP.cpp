/*
#include <boost/asio.hpp>
#include <iostream>

using boost::asio::ip::tcp;

int main() {
	try {
		boost::asio::io_context io_context; //io_service changed to io_context
		tcp::resolver resolver(io_context);
		//tcp::resolver::resolve query(tcp::v4(), "localhost", "12345"); Note: no longer exists
		// resolves "localhost" on port 12345
		auto endpoints = resolver.resolve("localhost", "12345");
		//tcp::resolver::iterator endpoint_iterator = resolver.resolve(query); //This code has been depricated

		//Can still iterate over however
		// you can still iterate over them if you want
		for (auto& ep : endpoints) {
			std::cout << ep.endpoint() << "\n";
		}

		// or just use them in connect()
		tcp::socket socket(io_context);
		// Connect directly with results_type (no iterator needed anymore)
		boost::asio::connect(socket, endpoints);

		const std::string msg = "Hello, World!\n";
		boost::asio::write(socket, boost::asio::buffer(msg, msg.size()));

		std::array<char, 128>buf;
		boost::system::error_code error;

		while (true) {
			size_t len = socket.read_some(boost::asio::buffer(buf), error);
			if (error == boost::asio::error::eof)
				break;
			else if (error)
				throw boost::system::system_error(error);

			std::cout.write(buf.data(), len);
		}

	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}

*/