// Create a class Book that includes private data members like title, author, and price. Use constructors to initialize them and display book details. Also implement a destructor to show object destruction.

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Book {
private:
    string title;
    string author;
    double price;

public:
    // Default constructor
    Book() : title("Unknown"), author("Unknown"), price(0.0) {
        cout << "[Default Constructor] Book object created." << endl;
    }

    // Parameterized constructor
    Book(const string& t, const string& a, double p)
        : title(t), author(a), price(p) {
        cout << "[Parameterized Constructor] Book object created: " << title << endl;
    }

    // Copy constructor
    Book(const Book& other)
        : title(other.title), author(other.author), price(other.price) {
        cout << "[Copy Constructor] Book object copied: " << title << endl;
    }

    // Destructor
    ~Book() {
        cout << "[Destructor] Book object destroyed: " << title << endl;
    }

    // Setters
    void setTitle(const string& t) { title = t; }
    void setAuthor(const string& a) { author = a; }
    void setPrice(double p) { price = p; }

    // Getters
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    double getPrice() const { return price; }

    // Function to display book details
    void display() const {
        cout << "\nBook Details:" << endl;
        cout << left << setw(10) << "Title:"  << title << endl;
        cout << left << setw(10) << "Author:" << author << endl;
        cout << left << setw(10) << "Price:"  << "₹" << fixed << setprecision(2) << price << endl;
    }

    // Function to input book details from user
    void input() {
        cout << "Enter book title: ";
        getline(cin, title);
        cout << "Enter author name: ";
        getline(cin, author);
        cout << "Enter price: ";
        cin >> price;
        cin.ignore(); // Clear newline from input buffer
    }
};

int main() {
    cout << "=== Book Class Demonstration ===\n" << endl;

    // Using default constructor and input function
    Book book1;
    book1.input();
    book1.display();

    // Using parameterized constructor
    Book book2("1984", "George Orwell", 15.99);
    book2.display();

    // Using setters
    Book book3;
    book3.setTitle("The Hobbit");
    book3.setAuthor("J.R.R. Tolkien");
    book3.setPrice(12.50);
    book3.display();

    // Using copy constructor
    Book book4 = book2;
    book4.display();

    // Demonstrate getters
    cout << "\nAccessing book2 details using getters:" << endl;
    cout << "Title: " << book2.getTitle() << endl;
    cout << "Author: " << book2.getAuthor() << endl;
    cout << "Price: ₹" << fixed << setprecision(2) << book2.getPrice() << endl;

    cout << "\nEnd of demonstration. Objects will now be destroyed as they go out of scope.\n";

    return 0;
}



// === Book Class Demonstration ===

// [Default Constructor] Book object created.
// Enter book title: Dune
// Enter author name: Frank Herbert
// Enter price: 18.99

// Book Details:
// Title:    Dune
// Author:   Frank Herbert
// Price:    ₹18.99
// [Parameterized Constructor] Book object created: 1984

// Book Details:
// Title:    1984
// Author:   George Orwell
// Price:    ₹15.99
// [Default Constructor] Book object created.

// Book Details:
// Title:    The Hobbit
// Author:   J.R.R. Tolkien
// Price:    ₹12.50
// [Copy Constructor] Book object copied: 1984

// Book Details:
// Title:    1984
// Author:   George Orwell
// Price:    ₹15.99

// Accessing book2 details using getters:
// Title: 1984
// Author: George Orwell
// Price: ₹15.99

// End of demonstration. Objects will now be destroyed as they go out of scope.
// [Destructor] Book object destroyed: 1984
// [Destructor] Book object destroyed: The Hobbit
// [Destructor] Book object destroyed: 1984
// [Destructor] Book object destroyed: Dune
