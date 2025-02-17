#include <iostream>
#include <windows.h>
#include <intrin.h>

using namespace std;

string getCPUID() {
    int cpuInfo[4] = {0};
    __cpuid(cpuInfo, 0);
    return to_string(cpuInfo[0]) + "-" + to_string(cpuInfo[1]) + "-" + to_string(cpuInfo[2]) + "-" + to_string(cpuInfo[3]);
}

int main() {
    cout << "CPU ID: " << getCPUID() << endl;
    return 0;
}
