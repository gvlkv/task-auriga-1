#include "algo2.hpp"

/// Реализовать алгоритм, определяющий что строка является палиндромом.
bool algo2(std::string_view str) {
  for (size_t i = 0; i < str.size() / 2; ++i) {
    if (str[i] != str[str.size() - 1 - i])
      return false;
  }
  return true;
}
