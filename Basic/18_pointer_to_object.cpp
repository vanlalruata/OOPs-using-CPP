#include <iostream>
#include <string>
#include <memory>

/**
 * @class Car
 * @brief A class to demonstrate pointers to objects.
 */
class Car {
private:
    std::string brand;
    int speed;

public:
    Car(const std::string& b, int s) : brand(b), speed(s) {}

    void show() const {
        std::cout << "Car Brand: " << brand << ", Speed: " << speed << " km/h" << std::endl;
    }

    /**
     * @brief A method demonstrating the 'this' pointer.
     * 
     * The 'this' pointer is a special pointer that exists within any non-static
     * member function. It points to the object for which the function was called.
     * It's used to access the object's own members.
     */
    Car* getThisPointer() {
        return this;
    }
};

int main() {
    // --- 1. Pointer to a Stack-Allocated Object ---
    std::cout << "--- 1. Pointer to Stack Object ---" << std::endl;
    Car stackCar("Ford", 180);
    Car* stackPtr = &stackCar; // Pointer 'stackPtr' holds the address of 'stackCar'.

    // The '->' (arrow) operator is used to access members of an object through a pointer.
    // It's shorthand for (*stackPtr).show().
    stackPtr->show();
    std::cout << "Address of stackCar: " << &stackCar << std::endl;
    std::cout << "Value of stackPtr:   " << stackPtr << std::endl;

    // --- 2. Pointer to a Heap-Allocated Object (Raw Pointer) ---
    std::cout << "\n--- 2. Pointer to Heap Object (Raw Pointer) ---" << std::endl;
    Car* heapPtr = new Car("Tesla", 220); // 'new' allocates memory on the heap.
    heapPtr->show();
    // DANGER: You are responsible for calling 'delete'. Forgetting leads to memory leaks.
    delete heapPtr;
    heapPtr = nullptr;

    // --- 3. Pointer to a Heap-Allocated Object (Smart Pointer) ---
    std::cout << "\n--- 3. Pointer to Heap Object (Smart Pointer - Recommended) ---" << std::endl;
    // A std::unique_ptr is a "smart pointer" that owns the object it points to.
    // It automatically calls 'delete' when it goes out of scope.
    std::unique_ptr<Car> smartPtr = std::make_unique<Car>("Audi", 250);
    smartPtr->show(); // You can use -> just like a raw pointer.
    // No 'delete' needed! Memory is managed automatically.

    // --- 4. The 'this' Pointer ---
    std::cout << "\n--- 4. The 'this' Pointer ---" << std::endl;
    Car anotherCar("BMW", 240);
    Car* thisPtr = anotherCar.getThisPointer();
    std::cout << "Address of anotherCar: " << &anotherCar << std::endl;
    std::cout << "Value of thisPtr:      " << thisPtr << std::endl;
    thisPtr->show(); // Proves 'thisPtr' points to 'anotherCar'.

    std::cout << "\nExiting main. Smart pointer will now clean up." << std::endl;
    return 0;
}
