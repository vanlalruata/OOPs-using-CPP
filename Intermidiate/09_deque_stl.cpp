#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> dq;
    dq.push_front(1);
    dq.push_back(2);

    cout << "Deque elements: ";
    for (int num : dq) {
        cout << num << " ";
    }
    cout << endl;

    dq.pop_front();
    dq.pop_back();

    cout << "Deque after popping: " << dq.size() << " elements left." << endl;
    return 0;
}
