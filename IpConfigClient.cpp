
/*
#include <boost/asio.hpp>
#include <iostream>

using boost::asio::ip::tcp;

int main() {
		boost::asio::io_context io_context; //io_service changed to io_context
		tcp::resolver resolver(io_context);
		//tcp::resolver::resolve query(tcp::v4(), "localhost", "12345"); Note: no longer exists
		// resolves "localhost" on port 12345
		auto endpoints = resolver.resolve("localhost", "1234");
		//tcp::resolver::iterator endpoint_iterator = resolver.resolve(query); //This code has been depricated

		// or just use them in connect()
		tcp::socket socket(io_context);
		// Connect directly with results_type (no iterator needed anymore)
		boost::asio::connect(socket, endpoints);

		std::string message = "Hello from client!\n";
		boost::system::error_code ignored_error;
		boost::asio::write(socket, boost::asio::buffer(message), ignored_error);

		char reply[1024];
		
		size_t reply_length = boost::asio::read(socket, boost::asio::buffer(reply, 1024), ignored_error);

		std::cout << "Reply is: ";
		std::cout.write(reply, reply_length);
		std::cout << "\n";
	return 0;
}

*/