#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> nums = {5, 2, 8, 1, 3};

    // Sort using lambda function
    sort(nums.begin(), nums.end(), [](int a, int b) { return a < b; });

    cout << "Sorted elements: ";
    for (int n : nums) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}
