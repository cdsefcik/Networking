
/*
#include<boost/asio.hpp>
#include<iostream>

using boost::asio::ip::tcp;

//Acceptes Connections and sends the response 

int main() {

	boost::asio::io_context io_context;

	tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), 1234));

	for (;;) {
		tcp::socket socket(io_context);
		acceptor.accept(socket);

		std::string data = "Hello from server!";
		boost::system::error_code ignored_error;
		boost::asio::write(socket, boost::asio::buffer(data), ignored_error);
	}

}

*/