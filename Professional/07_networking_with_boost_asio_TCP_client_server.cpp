#include <iostream>
#include <boost/asio.hpp>
using namespace std;
using namespace boost::asio;

int main() {
    io_service io;
    ip::tcp::acceptor acceptor(io, ip::tcp::endpoint(ip::tcp::v4(), 1234));
    ip::tcp::socket socket(io);

    cout << "Server waiting for connection..." << endl;
    acceptor.accept(socket);
    
    cout << "Client connected!" << endl;
    string message = "Hello from Server";
    write(socket, buffer(message));
    
    return 0;
}
