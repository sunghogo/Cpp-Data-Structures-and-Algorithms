#include <iostream>
#include "big_o/constant_time.h"

void AddThenPrintItems(int n) {
  std::cout << "Adding " << n << " + " << n << " + " << n << "...\n";
  std::cout << n + n + n << std::endl;
}
