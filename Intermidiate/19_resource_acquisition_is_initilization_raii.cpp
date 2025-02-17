#include <iostream>
using namespace std;

class Resource {
public:
    Resource() { cout << "Resource acquired!" << endl; }
    ~Resource() { cout << "Resource released!" << endl; }
};

void function() {
    Resource res;  // Automatically managed
}

int main() {
    function();  // Resource allocated & freed automatically
    return 0;
}
