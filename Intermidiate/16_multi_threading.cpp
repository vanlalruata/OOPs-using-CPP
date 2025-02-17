#include <iostream>
#include <thread>
using namespace std;

void task1() {
    cout << "Task 1 is running" << endl;
}

void task2() {
    cout << "Task 2 is running" << endl;
}

int main() {
    thread t1(task1);
    thread t2(task2);

    t1.join();  // Wait for t1 to finish
    t2.join();  // Wait for t2 to finish

    cout << "Main function completed" << endl;
    return 0;
}
