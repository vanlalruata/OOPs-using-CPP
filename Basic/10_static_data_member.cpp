#include <iostream>

/**
 * @class Thing
 * @brief Demonstrates static data members and member functions.
 */
class Thing {
private:
    // A non-static data member. Each object of the class gets its own copy.
    int objectID;

    // A static data member. There is only one copy of this variable, shared
    // by all objects of the Thing class. It belongs to the class itself,
    // not to any particular object.
    static int objectCount;

public:
    /**
     * @brief Constructor that increments the static count and assigns a unique ID.
     */
    Thing() {
        // Assign the current count as the ID for the new object,
        // then increment the shared count.
        objectID = ++objectCount;
        std::cout << "Thing created. ID: " << objectID << std::endl;
    }

    /**
     * @brief Destructor that decrements the static count.
     */
    ~Thing() {
        std::cout << "Thing destroyed. ID: " << objectID << std::endl;
        // Decrement the shared count as an object is destroyed.
        objectCount--;
    }

    /**
     * @brief A non-static member function that can access both static and non-static members.
     */
    void showID() {
        std::cout << "My ID is " << objectID << std::endl;
    }

    /**
     * @brief A static member function.
     * 
     * Static member functions can only access static data members and other
     * static member functions. They do not have a 'this' pointer because
     * they are not associated with a specific object.
     */
    static void showCount() {
        std::cout << "Total active Things: " << objectCount << std::endl;
        // The following line would cause a compiler error because a static function
        // cannot access a non-static member:
        // std::cout << "My ID is " << objectID << std::endl;
    }
};

// The static data member must be initialized outside the class, typically in the .cpp file.
// This allocates storage for the static variable.
int Thing::objectCount = 0;

int main() {
    std::cout << "--- Program Start ---" << std::endl;
    Thing::showCount(); // We can call a static function without any objects.

    std::cout << "\nCreating first Thing..." << std::endl;
    Thing t1;
    t1.showID();
    Thing::showCount();

    std::cout << "\nCreating more Things..." << std::endl;
    Thing t2, t3;
    t2.showID();
    t3.showID();
    Thing::showCount();

    {
        std::cout << "\nEntering a new scope..." << std::endl;
        Thing t4;
        t4.showID();
        Thing::showCount();
        std::cout << "Exiting scope..." << std::endl;
    } // t4 is destroyed here as it goes out of scope.

    std::cout << "\nAfter scope exit..." << std::endl;
    Thing::showCount();

    std::cout << "\n--- Program End ---" << std::endl;
    // t1, t2, and t3 are destroyed here at the end of main.
    return 0;
}
