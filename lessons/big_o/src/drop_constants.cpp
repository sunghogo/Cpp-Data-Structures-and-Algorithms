#include <iostream>
#include "big_o/drop_constants.h"

void PrintItemsLinearTimeTwice(int n) {
  std::cout << "Printing O(n) x2...\n";
  for (int i = 0; i < n; i++) {
    std::cout << i << " ";
  }
  std::cout << '\n';
  for (int i = 0; i < n; i++) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}
