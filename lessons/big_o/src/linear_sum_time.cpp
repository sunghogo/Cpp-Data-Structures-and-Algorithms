#include <iostream>
#include "big_o/linear_sum_time.h"

void PrintItemsLinearSumTime(int n, int m) {
  std::cout << "Printing O(n + m)...\n";
  for (int i = 0; i < n; i++) {
    std::cout << i << " ";
  }
  std::cout << '\n';
  for (int i = 0; i < m; i++) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}
