#include "algo1.hpp"
#include "algo2.hpp"
#include "algo3.hpp"
#include "algo4.hpp"
#include "algo6.hpp"
#include <iostream>
#include <ranges>
#include <string_view>

int main(int argc, char **argv) {
  std::cout << std::boolalpha;
  if (argc != 2)
    return 1;
  if (std::string(argv[1]) == "algo1") {
    std::string in;
    std::getline(std::cin, in);
    std::cout << algo1(in) << "\n";
  } else if (std::string(argv[1]) == "algo2") {
    std::string in;
    std::getline(std::cin, in);
    std::cout << algo2(in) << "\n";
  } else if (std::string(argv[1]) == "algo3") {
    std::vector<std::vector<int>> mat;
    for (;;) {
      std::string in;
      std::getline(std::cin, in);
      if (in.empty())
        break;

      mat.push_back({});
      auto split =
          in | std::ranges::views::split(' ') |
          std::ranges::views::transform([](auto &&str) {
            return std::string_view(&*str.begin(), std::ranges::distance(str));
          });
      for (auto &&entry : split) {
        mat[mat.size() - 1].push_back(std::stoi(std::string(entry)));
      }
    };
    algo3(mat);
    for (auto &row : mat) {
      for (int elem : row) {
        std::cout << elem << " ";
      }
      std::cout << "\n";
    }
  } else if (std::string(argv[1]) == "algo4") {
    std::string in;
    Node<std::string> *list = nullptr;
    for (;;) {
      std::getline(std::cin, in);
      auto new_node = new Node<std::string>;
      new_node->next = list;
      new_node->value = in;
      list = new_node;
      if (in.empty())
        break;
    }
    remove_duplicates(list);
    display_list(list);
  } else if (std::string(argv[1]) == "algo6") {
    std::string in;
    std::cin >> in;
    std::cout << check_brackets(in) << "\n";
  }
}
