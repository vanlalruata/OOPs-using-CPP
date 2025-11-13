#include <iostream>
#include <string>
#include <memory> // Required for smart pointers

/**
 * @class Student
 * @brief A simple class to demonstrate dynamic memory allocation.
 */
class Student {
private:
    std::string name;
    int age;

public:
    Student(const std::string& n, int a) : name(n), age(a) {
        std::cout << "Constructor called for " << name << std::endl;
    }

    ~Student() {
        std::cout << "Destructor called for " << name << std::endl;
    }

    void display() const {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

void demonstrate_raw_pointers() {
    std::cout << "--- 1. Manual Memory Management with Raw Pointers (Old C-style) ---" << std::endl;
    // Memory is allocated on the heap. The programmer is responsible for deallocation.
    Student* s1 = new Student("Alice", 20);
    s1->display();

    // Forgetting this 'delete' call would cause a memory leak.
    delete s1;
    s1 = nullptr; // Good practice to null out pointers after deletion.

    std::cout << "\n--- 2. Dynamic Array with Raw Pointers ---" << std::endl;
    // Allocating an array of objects.
    Student* student_array = new Student[3]{ {"Bob", 22}, {"Charlie", 23}, {"David", 21} };
    
    // Must use delete[] for arrays, otherwise it's undefined behavior.
    delete[] student_array;
    student_array = nullptr;
}

void demonstrate_smart_pointers() {
    std::cout << "\n--- 3. Automatic Memory Management with Smart Pointers (Modern C++) ---" << std::endl;
    
    // Use std::unique_ptr for exclusive ownership of a resource.
    // std::make_unique is the recommended way to create a unique_ptr.
    // It's safer and more efficient than using 'new' directly.
    std::unique_ptr<Student> s2 = std::make_unique<Student>("Eve", 25);
    
    s2->display();

    // No 'delete' is needed! The memory is automatically freed when 's2'
    // goes out of scope. This is called RAII (Resource Acquisition Is Initialization).
    std::cout << "s2 is about to go out of scope..." << std::endl;
}

int main() {
    // Stack vs. Heap Allocation
    // 's_stack' is allocated on the stack and is automatically destroyed
    // when it goes out of scope at the end of main.
    std::cout << "--- Creating a stack-allocated object ---" << std::endl;
    Student s_stack("Frank", 30);
    s_stack.display();
    std::cout << "--- Stack object is about to go out of scope ---" << std::endl;

    std::cout << std::endl;

    demonstrate_raw_pointers();
    demonstrate_smart_pointers();

    std::cout << "\n--- End of main ---" << std::endl;
    return 0;
}
