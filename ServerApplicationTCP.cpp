
//#include <boost/asio.hpp>
//#include<iostream>

/*
This is a server shell
Also contains code for advanced error handling.

*/

/*

using boost::asio::ip::tcp;  

int main() {

	try {
		boost::asio::io_context io_service; //io_service changed to io_context

		tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(), 12345)); //This is the server socket that waits for connections: Parameters: where to register operations, this is ipv4, socket number 12345

		for (;;) {
			tcp::socket socket(io_service);
			acceptor.accept(socket);
			std::array<char, 128>buf;
			boost::system::error_code error;

			while (true) {
				size_t len = socket.read_some(boost::asio::buffer(buf), error);
				if (error == boost::asio::error::eof) {
					break;
				}
				else if(error) {
					throw boost::system::system_error(error);
				}

				boost::asio::write(socket, boost::asio::buffer(buf, len));
			}

		}

	}
	catch (boost::system::system_error& e) {
		if (e.code() == boost::asio::error::connection_refused) {
			std::cerr << "Connection refused" << std::endl;
		}
		else if (e.code() == boost::asio::error::timed_out) {
			std::cerr << "Connection Timed Out" << std::endl;
		}
		else if (e.code() == boost::asio::error::host_unreachable) {
			std::cerr << "Host Unreachable" << std::endl;
		}
		else if (e.code() == boost::asio::error::address_in_use) {
			std::cerr << "Address in use" << std::endl;
		}
		else if (e.code() == boost::asio::error::connection_reset || e.code() == boost::asio::error::broken_pipe) {
			std::cerr << "Connection forcibly closed by peer" << std::endl;
		}
		else {
			std::cerr <<"Other Error"<< e.what() << std::endl;
		}

		
	}

	return 0;
}

**/