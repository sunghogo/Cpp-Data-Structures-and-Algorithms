#include <iostream>

using namespace std;

// O(2) = O(1), constant operations
int addItems(int n) { 
    return n + n + n;
}

int main() {
    cout << addItems(10) << endl;
    return 0;
}