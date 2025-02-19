#include <iostream>
using namespace std;

enum Day {SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY};

int main() {
    Day today = WEDNESDAY;

    if (today == WEDNESDAY) {
        cout << "It's midweek!" << endl;
    }

    return 0;
}
