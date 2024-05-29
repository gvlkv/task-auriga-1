#include <iostream>
#include <unordered_set>

template <class T> struct Node {
  T value;
  Node<T> *next;
};

/// Напишите функцию которая убирает дубликаты из несортированного односвязного
/// списка.
template <class T> void remove_duplicates(Node<T> *list) {
  if (!list)
    return;
  std::unordered_set<T> seen;

  while (true) {
    Node<T> *next = list->next;
    if (!next)
      return;

    if (seen.contains(next->value)) {
      list->next = next->next;
      delete next;
    } else {
      seen.insert(next->value);
      list = list->next;
      if (!list)
        return;
    }
  }
}

template <class T> void display_list(Node<T> *list) {
  for (Node<T> *cur = list; cur != nullptr; cur = cur->next) {
    std::cout << cur->value << "\n";
  }
}
