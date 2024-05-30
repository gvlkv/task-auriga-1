#ifndef NODE_H_
#define NODE_H_

template <class T> struct Node {
  T value;
  Node<T> *next;
};

#endif // NODE_H_
