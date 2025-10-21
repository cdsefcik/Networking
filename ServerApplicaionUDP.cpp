/**
#include <boost/asio.hpp>
#include <iostream>

using boost::asio::ip::udp;

int main() {
	try {
		boost::asio::io_context io_context; //io_service changed to io_context

		udp::socket socket(io_context, udp::endpoint(udp::v4(), 12345));

		for (;;) {
			std::array<char, 1024> recv_buf;
			udp::endpoint remote_endpoint;
			boost::system::error_code error;

			//receive
			size_t len = socket.receive_from(boost::asio::buffer(recv_buf), remote_endpoint, 0, error);
			if (error && error != boost::asio::error::message_size) {
				throw boost::system::system_error(error);
			}

			socket.send_to(boost::asio::buffer(recv_buf.data(), len), remote_endpoint, 0, error);
		}
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}

**/