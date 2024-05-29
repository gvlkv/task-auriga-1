#include "algo6.hpp"

#include <stack>
#include <unordered_map>

const std::unordered_map<char, char> map = {{')', '('}, {']', '['}, {'}', '{'}};

/// Напишите функцию которая проверяет корректность произвольной скобочной
/// структуры типа {()[]((())}{} (корректной считается структура где каждая
/// открывающая скобка имеет комплементарную ей закрывающую с учетом порядка
/// следования пар).
bool check_brackets(std::string_view input) {
  std::stack<char> stack;

  for (char ch : input) {
    switch (ch) {
    case '(':
    case '[':
    case '{':
      stack.push(ch);
      break;
    case ')':
    case ']':
    case '}':
      if (stack.empty() || stack.top() != map.at(ch))
        return false;
      stack.pop();
      break;
    }
  }

  return stack.empty();
}
