#include <iostream>

using namespace std;

// O(2n) = O(n), drop constants
void printItems(int n) {
    for (int i {0}; i < n; i++)
        cout << i << endl;

    for (int i {0}; i < n; i++)
        cout << i << endl;
}

int main() {
    printItems(20);
    return 0;
}