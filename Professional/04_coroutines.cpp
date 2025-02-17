#include <iostream>
#include <coroutine>
using namespace std;

struct Coroutine {
    struct promise_type {
        Coroutine get_return_object() { return {}; }
        suspend_never initial_suspend() { return {}; }
        suspend_never final_suspend() noexcept { return {}; }
        void return_void() {}
        void unhandled_exception() { terminate(); }
    };
};

Coroutine simpleCoroutine() {
    cout << "Inside coroutine" << endl;
    co_return;
}

int main() {
    simpleCoroutine();
    cout << "Back in main" << endl;
    return 0;
}
