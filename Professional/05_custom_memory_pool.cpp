#include <iostream>
#include <vector>
using namespace std;

class MemoryPool {
    vector<char*> blocks;
    size_t blockSize;

public:
    MemoryPool(size_t size) : blockSize(size) {
        blocks.push_back(new char[blockSize]);
    }

    void* allocate(size_t size) {
        if (size > blockSize) return nullptr;
        return blocks.back();
    }

    void deallocate(void* ptr) {
        // No real deallocation in simple memory pools
    }

    ~MemoryPool() {
        for (char* block : blocks)
            delete[] block;
    }
};

int main() {
    MemoryPool pool(1024);
    void* mem = pool.allocate(100);
    cout << "Memory allocated from pool: " << mem << endl;
    return 0;
}
