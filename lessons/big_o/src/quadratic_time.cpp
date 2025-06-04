#include <iostream>
#include "big_o/quadratic_time.h"

void PrintItemsQuadraticTime(int n) {
  std::cout << "Printing O(n^2)...\n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i) std::cout << i;
      std::cout << j << " ";
    }
  }
  std::cout << std::endl;
}
