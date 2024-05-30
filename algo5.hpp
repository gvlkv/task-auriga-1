#ifndef ALGO5_H_
#define ALGO5_H_

#include "node.hpp"

/// Напишите функцию которая выводит общий элемент для двух пересекающихся
/// односвязных списков.
template <class T> Node<T> *common_element(Node<T> *list1, Node<T> *list2) {
  for (Node<T> *it1 = list1; it1; it1 = it1->next) {
    for (Node<T> *it2 = list2; it2; it2 = it2->next) {
      if (it1->value == it2->value) {
        return it1;
      }
    }
  }
  return nullptr;
}

#endif // ALGO5_H_
