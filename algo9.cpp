#include "algo9.hpp"
#include <unordered_map>

std::unordered_map<int, long long> number_of_ways_memoized;
static long long number_of_ways_inner(int rungs);

/// Допустим, ребенок бежит вверх по лестнице, состоящей из n ступенек. Ребенок
/// может прыгать на 1 шаг, 2 шага, или 3 шага за раз. Напишите функцию
///  steps(n), которая возвращает количество различных способов, которыми
/// ребенок может подняться по лестнице.
long long number_of_ways(int rungs) {
  if (number_of_ways_memoized.contains(rungs))
    return number_of_ways_memoized[rungs];
  return number_of_ways_memoized[rungs] = number_of_ways_inner(rungs);
}

static long long number_of_ways_inner(int rungs) {
  if (rungs == 1)
    return 1;
  if (rungs == 2)
    return 1;
  if (rungs == 3)
    return 2;
  if (rungs == 4)
    return 4;

  return number_of_ways(rungs - 1) + number_of_ways(rungs - 2) +
         number_of_ways(rungs - 3);
}
