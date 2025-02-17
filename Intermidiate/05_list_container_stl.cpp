#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> myList = {1, 2, 3, 4, 5};

    myList.push_front(0);
    myList.push_back(6);

    cout << "List elements: ";
    for (int num : myList) {
        cout << num << " ";
    }
    cout << endl;

    myList.pop_front();
    myList.pop_back();

    cout << "After pop operations: ";
    for (int num : myList) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
