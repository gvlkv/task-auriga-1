#ifndef ALGO8_BINARY_H_
#define ALGO8_BINARY_H_

#include <span>

/// Напишите программу бинарного поиска по списку используя рекурсию.
template <class T>
T *binary_search(const std::span<T> haystack, const T &needle) {
  if (haystack.empty())
    return nullptr;

  size_t mid = haystack.size() / 2;

  if (haystack[mid] == needle)
    return &haystack[mid];

  if (haystack[mid] > needle) {
    return binary_search(std::span<T>(haystack.begin(), haystack.begin() + mid),
                         needle);
  } else {
    return binary_search(
        std::span<T>(haystack.begin() + mid + 1, haystack.end()), needle);
  }
}
#endif // #IFNDEF ALGO8_BINARY_H_
