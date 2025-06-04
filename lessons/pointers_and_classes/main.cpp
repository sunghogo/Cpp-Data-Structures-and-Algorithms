#include <iostream>
#include <pointers_and_classes/cookies.h>

int main() {
  // Raw Pointers Example
  std::cout << "Starting Raw Pointers Example...\n";
  int num1 = 11;    // num1 contains value 11
  int num2 = num1;  // num2 copies value of num1

  num2 = 22;

  std::cout << "num1 = " << num1 << '\n';
  std::cout << "num2 = " << num2 << '\n';

  int* num3 = new int(11);  // num3 contains address that contains value 11
  int* num4 = num3;  // num4 copies value of num3, which is the address that
                     // contains value 11

  std::cout << "num3 = " << num3 << '\n';
  std::cout << "num4 = " << num4 << '\n';

  *num4 = 22;

  std::cout << "*num3 = " << *num3 << '\n';
  std::cout << "*num4 = " << *num4 << '\n';

  delete num3;

  // Classes Example
  std::cout << "Starting Classes Example...\n";
  Cookie* cookieOne = new Cookie("green");
  Cookie* cookieTwo = new Cookie("blue");

  std::cout << "C1: " << cookieOne->GetColor() << '\n';
  std::cout << "C2: " << cookieTwo->GetColor() << '\n';

  cookieOne->SetColor("yellow");

  std::cout << "C1: " << cookieOne->GetColor() << '\n';
  std::cout << "C2: " << cookieTwo->GetColor() << '\n';

  std::cout << std::endl;

  return 0;
}
