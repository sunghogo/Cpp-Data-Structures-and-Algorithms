#include <iostream>

using namespace std;

int main() {
    int num1 = 11; // num1 contains value 11
    int num2 = num1; // num2 copies value of num1
    
    num2 = 22;

    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;

    int *num3 = new int(11); // num3 contains address that contains value 11
    int *num4 = num3; // num4 copies value of num3, which is the address that contains value 11

    cout << "num3 = " << num3 << endl;
    cout << "num4 = " << num4 << endl;

    *num4 = 22;

    cout << "*num3 = " << *num3 << endl;
    cout << "*num4 = " << *num4 << endl;

    delete num3, num4;
    
    return 0;
}