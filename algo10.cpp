#include "algo10.hpp"

/// Напишите функцию, которая вернет наибольшую сумму для ряда чисел, являющихся
/// подмножеством данного ряда.
int max_subsum(std::vector<int> const &vec) {
  int sums = 0;
  int min = 0;
  int max = 0;
  for (int v : vec) {
    sums += v;
    if (sums > max)
      max = sums;
    if (sums < min)
      min = sums;
  }
  return max - min;
}
