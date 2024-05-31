#include "algo7-sort.hpp"

static std::vector<int> merge_sorted(const std::vector<int> &left,
                                     const std::vector<int> &right);

std::vector<int> sort(const std::vector<int> &vec) {
  if (vec.size() < 2)
    return vec;

  size_t mid = vec.size() / 2;
  auto left = std::vector<int>(vec.begin(), vec.begin() + mid);
  auto right = std::vector<int>(vec.begin() + mid, vec.end());

  left = sort(left);
  right = sort(right);
  return merge_sorted(left, right);
}

static std::vector<int> merge_sorted(const std::vector<int> &left,
                                     const std::vector<int> &right) {
  std::vector<int> result;
  result.reserve(left.size() + right.size());

  auto left_ptr = left.begin();
  auto right_ptr = right.begin();

  while (left_ptr != left.end() && right_ptr != right.end()) {
    if (*left_ptr < *right_ptr) {
      result.push_back(*left_ptr);
      ++left_ptr;
    } else {
      result.push_back(*right_ptr);
      ++right_ptr;
    }
  }
  if (right_ptr == right.end()) {
    while (left_ptr != left.end()) {
      result.push_back(*left_ptr++);
    }
  }
  if (left_ptr == left.end()) {
    while (right_ptr != right.end()) {
      result.push_back(*right_ptr++);
    }
  }
  return result;
}
