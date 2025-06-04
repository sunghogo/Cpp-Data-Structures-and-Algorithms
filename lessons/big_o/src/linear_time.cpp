#include <iostream>
#include "big_o/linear_time.h"

void PrintItemsLinearTime(int n) {
  std::cout << "Printing O(n)...\n";
  for (int i = 0; i < n; i++) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}
