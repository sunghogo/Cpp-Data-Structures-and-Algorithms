#include <iostream>

using namespace std;

// O(n + m), different terms for inputs
void printItems(int a, int b) {
    for (int i {0}; i < a; i++)
        cout << i << endl;

    for (int j {0}; j < b; j++)
        cout << j << endl;

}

int main() {
    printItems(10, 10);
    return 0;
}