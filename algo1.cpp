#include "algo1.hpp"
#include <algorithm>
#include <iterator>
#include <unordered_set>

/// Реализовать алгоритм, определяющий что строка содержит только уникальные
/// символы.
bool algo1(std::string_view str) {
  std::unordered_set<char> set;
  std::copy(str.begin(), str.end(), std::inserter(set, set.begin()));
  const bool result = set.size() == str.size();
  return result;
}
