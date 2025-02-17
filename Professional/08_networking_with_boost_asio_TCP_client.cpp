#include <iostream>
#include <boost/asio.hpp>
using namespace std;
using namespace boost::asio;

int main() {
    io_service io;
    ip::tcp::socket socket(io);
    socket.connect(ip::tcp::endpoint(ip::address::from_string("127.0.0.1"), 1234));
    
    char buffer[1024];
    size_t len = socket.read_some(buffer(buffer, sizeof(buffer)));
    
    cout << "Server says: " << string(buffer, len) << endl;
    return 0;
}
