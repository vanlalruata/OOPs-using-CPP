#include <iostream>
#include <string>

/**
 * @class Animal
 * @brief The base class in our inheritance example.
 */
class Animal {
protected:
    // protected members are accessible in the derived class but not by the public.
    std::string name;

public:
    // Constructor for the base class.
    Animal(const std::string& n) : name(n) {
        std::cout << "Animal constructor called for " << name << std::endl;
    }

    // A virtual destructor is crucial for a base class. If you delete a
    // derived class object through a pointer to the base class, this ensures
    // that the derived class's destructor is called first.
    virtual ~Animal() {
        std::cout << "Animal destructor called for " << name << std::endl;
    }

    // A virtual function that can be overridden by derived classes.
    virtual void makeSound() const {
        std::cout << name << " makes a generic animal sound." << std::endl;
    }

    void eat() const {
        std::cout << name << " eats food." << std::endl;
    }
};

/**
 * @class Dog
 * @brief The derived class, inheriting from Animal.
 */
class Dog : public Animal {
private:
    std::string breed;

public:
    // The Dog constructor calls the Animal constructor using the member initializer list.
    Dog(const std::string& n, const std::string& b) : Animal(n), breed(b) {
        std::cout << "Dog constructor called for " << name << std::endl;
    }

    ~Dog() {
        std::cout << "Dog destructor called for " << name << std::endl;
    }

    /**
     * @brief Overrides the base class's makeSound function.
     * The 'override' keyword is optional but recommended. It tells the compiler
     * that you intend to override a virtual function, and the compiler will
     * give an error if no such function exists in the base class.
     */
    void makeSound() const override {
        std::cout << name << " the " << breed << " barks!" << std::endl;
    }

    // A new function specific to the Dog class.
    void wagTail() const {
        std::cout << name << " wags its tail." << std::endl;
    }
};

int main() {
    std::cout << "--- Creating a Dog object directly ---" << std::endl;
    Dog myDog("Buddy", "Golden Retriever");
    myDog.eat();       // Calling a method from the base class.
    myDog.makeSound(); // Calling the overridden method in the derived class.
    myDog.wagTail();   // Calling a method specific to the derived class.

    std::cout << "\n--- Demonstrating Polymorphism ---" << std::endl;
    // Create a pointer to the base class that points to a derived class object.
    Animal* pAnimal = new Dog("Daisy", "Beagle");

    pAnimal->eat();       // Calls Animal::eat()
    pAnimal->makeSound(); // Calls the overridden Dog::makeSound() because makeSound is virtual.

    // The following line would cause a compiler error because wagTail() is not
    // a member of the Animal class.
    // pAnimal->wagTail();

    // Deleting the object through the base class pointer.
    // The virtual destructor ensures both Dog's and Animal's destructors are called.
    delete pAnimal;

    return 0;
}
