/*
#include <boost/asio.hpp>
#include <iostream>

using boost::asio::ip::udp;

int main() {
	try {
		boost::asio::io_context io_context;

		// Modern API (no query object)

		udp::resolver resolver(io_context);
		//udp::resolver::query query(udp::v4(), "localhost", "12345");
		//udp::endpoint receiver_endpoint = *resolver.resolve(query);
		auto results = resolver.resolve(udp::v4(), "localhost", "12345");
		udp::endpoint receiver_endpoint = *results.begin();

		udp::socket socket(io_context);
		socket.open(udp::v4());

		std::array<char, 1024> send_buf = { "Hello, World!\n" };
		socket.send_to(boost::asio::buffer(send_buf, 13), receiver_endpoint);

		std::array<char, 1024>recv_buf;
		udp::endpoint sender_endpoint;

		size_t len = socket.receive_from(boost::asio::buffer(recv_buf), sender_endpoint);

		std::cout.write(recv_buf.data(), len);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}

*/