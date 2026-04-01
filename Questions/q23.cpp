#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Book {
private:
    string title, author;
public:
    Book(string t, string a) {
        title = t;
        author = a;
    }
    void display() {
        cout << "Title: " << title << ", Author: " << author << endl;
    }
    string getTitle() { return title; }
};

class Library {
private:
    vector<Book> books;
public:
    void addBook(Book b) {
        books.push_back(b);
    }
    void displayBooks() {
        for(auto& b : books) b.display();
    }
    void searchBook(string title) {
        for(auto& b : books) {
            if(b.getTitle() == title) {
                b.display();
                return;
            }
        }
        cout << "Book not found" << endl;
    }
};

int main() {
    Library lib;
    lib.addBook(Book("C++", "Bjarne"));
    lib.addBook(Book("Java", "James"));
    lib.displayBooks();
    lib.searchBook("C++");
    return 0;
}