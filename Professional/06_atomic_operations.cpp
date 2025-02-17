#include <iostream>
#include <thread>
#include <atomic>
using namespace std;

atomic<int> counter(0);

void increment() {
    for (int i = 0; i < 1000; i++) {
        counter.fetch_add(1, memory_order_relaxed);
    }
}

int main() {
    thread t1(increment);
    thread t2(increment);
    
    t1.join();
    t2.join();

    cout << "Final counter value: " << counter << endl;
    return 0;
}
