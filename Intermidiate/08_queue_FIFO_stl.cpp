#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;
    q.push(100);
    q.push(200);
    q.push(300);

    cout << "Front: " << q.front() << ", Back: " << q.back() << endl;
    q.pop();
    cout << "After pop, Front: " << q.front() << endl;

    return 0;
}
