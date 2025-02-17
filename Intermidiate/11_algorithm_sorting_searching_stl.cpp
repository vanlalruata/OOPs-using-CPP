#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> nums = {50, 20, 30, 10, 40};

    sort(nums.begin(), nums.end());  // Sorting

    cout << "Sorted elements: ";
    for (int n : nums) {
        cout << n << " ";
    }
    cout << endl;

    if (find(nums.begin(), nums.end(), 30) != nums.end()) {
        cout << "Element 30 found in the vector!" << endl;
    } else {
        cout << "Element 30 not found!" << endl;
    }

    return 0;
}
