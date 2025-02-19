#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) return i;
    }
    return -1;
}

int main() {
    int arr[] = {3, 7, 1, 9, 5};
    int key;
    cout << "Enter number to search: ";
    cin >> key;

    int index = linearSearch(arr, 5, key);
    if (index != -1) cout << "Element found at index " << index << endl;
    else cout << "Element not found" << endl;
    return 0;
}
