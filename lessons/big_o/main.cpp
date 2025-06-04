#include "big_o/linear_time.h"
#include "big_o/drop_constants.h"
#include "big_o/quadratic_time.h"
#include "big_o/drop_nondominants.h"
#include "big_o/constant_time.h"
#include "big_o/linear_sum_time.h"

int main() {
  PrintItemsLinearTime(20);
  PrintItemsLinearTimeTwice(10);
  PrintItemsQuadraticTime(10);
  PrintItemsQuadratricThenLinearTime(10);
  AddThenPrintItems(5);
  PrintItemsLinearSumTime(3, 7);
  return 0;
}
