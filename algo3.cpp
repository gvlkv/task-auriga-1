#include "algo3.hpp"

/// Напишите алгоритм, который принимает матрицу N x M и для любого элемента
/// матрицы, равного нулю, устанавливает всю строку и столбец, содержащие этот
/// элемент, равным 0.
void algo3(std::vector<std::vector<int>> &mat) {
  std::vector<std::pair<int, int>> zero_indices;
  const int width = mat[0].size();
  const int height = mat.size();
  for (int j = 0; j < height; ++j) {
    for (int i = 0; i < width; ++i) {
      if (mat[j][i] == 0)
        zero_indices.push_back({j, i});
    }
  }
  for (const auto &p : zero_indices) {
    for (int j = 0; j < height; ++j)
      mat[j][p.second] = 0;
    for (int i = 0; i < width; ++i)
      mat[p.first][i] = 0;
  }
}
