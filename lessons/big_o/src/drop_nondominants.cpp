#include <iostream>
#include "big_o/drop_nondominants.h"

void PrintItemsQuadratricThenLinearTime(int n) {
  std::cout << "Printing O(n^2) + O(n)...\n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i) std::cout << i;
      std::cout << j << " ";
    }
  }
  std::cout << '\n';
  for (int i = 0; i < n; i++) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}
