#include <iostream>
#include <string>

/**
 * @class PoweredDevice
 * @brief The base class in a diamond inheritance hierarchy.
 */
class PoweredDevice {
public:
    PoweredDevice(int deviceID) : id(deviceID) {
        std::cout << "PoweredDevice constructor called. ID: " << id << std::endl;
    }
    virtual ~PoweredDevice() {
        std::cout << "PoweredDevice destructor called." << std::endl;
    }
    void turnOn() {
        std::cout << "Device " << id << " is on." << std::endl;
    }
protected:
    int id;
};

/**
 * @class Scanner
 * @brief Inherits from PoweredDevice.
 *
 * Without 'virtual' inheritance, an object of a class that inherits from both
 * Scanner and Printer would contain two separate PoweredDevice subobjects.
 * This is the "diamond problem."
 *
 * By using 'virtual public', we ensure that any class inheriting from Scanner
 * will share a single instance of the PoweredDevice base class.
 */
class Scanner : virtual public PoweredDevice {
public:
    Scanner(int scannerId, int deviceId) : PoweredDevice(deviceId) {
        std::cout << "Scanner constructor called." << std::endl;
    }
    ~Scanner() {
        std::cout << "Scanner destructor called." << std::endl;
    }
    void scan() {
        std::cout << "Scanning with device " << id << "." << std::endl;
    }
};

/**
 * @class Printer
 * @brief Also inherits from PoweredDevice.
 */
class Printer : virtual public PoweredDevice {
public:
    Printer(int printerId, int deviceId) : PoweredDevice(deviceId) {
        std::cout << "Printer constructor called." << std::endl;
    }
    ~Printer() {
        std::cout << "Printer destructor called." << std::endl;
    }
    void print() {
        std::cout << "Printing with device " << id << "." << std::endl;
    }
};

/**
 * @class Copier
 * @brief Inherits from both Scanner and Printer.
 */
class Copier : public Scanner, public Printer {
public:
    /**
     * When using virtual inheritance, the most derived class (Copier) is
     * responsible for constructing the virtual base class (PoweredDevice).
     * The constructors of the intermediate classes (Scanner, Printer) for the
     * virtual base are ignored.
     */
    Copier(int scannerId, int printerId, int deviceId)
        : PoweredDevice(deviceId), Scanner(scannerId, deviceId), Printer(printerId, deviceId) {
        std::cout << "Copier constructor called." << std::endl;
    }
    ~Copier() {
        std::cout << "Copier destructor called." << std::endl;
    }
};

int main() {
    std::cout << "--- Creating a Copier object ---" << std::endl;
    Copier myCopier(101, 202, 909);

    std::cout << "\n--- Using the Copier ---" << std::endl;
    // Because of virtual inheritance, there is only one PoweredDevice subobject,
    // so there is no ambiguity when calling turnOn().
    myCopier.turnOn();
    myCopier.scan();
    myCopier.print();

    std::cout << "\n--- Destroying the Copier object ---" << std::endl;
    // The destructors are called in the reverse order of construction.
    return 0;
}
