#include "algo11.hpp"
#include <iostream>

/// Имея корень двоичного дерева поиска, состоящего из узлов с некоторыми целыми
/// значениями, и значение x, реализуйте алгоритм под названием
/// find_closest(root,x), который возвращает ближайшую к x точку в бинарном
/// дереве поиска.
TreeNode *find_closest(TreeNode *root, int x, TreeNode *last_left,
                       TreeNode *last_right) {
  if (root == nullptr) {
    if (!last_left && !last_right)
      return nullptr;
    if (!last_left)
      return last_right;
    if (!last_right)
      return last_left;
    if (x - last_left->value > last_right->value - x) {
      return last_left;
    } else {
      return last_right;
    }
  }
  if (root->value == x)
    return root;
  if (root->value < x) {
    return find_closest(root->right, x, last_left, root);
  } else {
    return find_closest(root->left, x, root, last_right);
  }
}

void tree_insert(TreeNode **root, int value) {
  if (*root == nullptr) {
    *root = new TreeNode{value, nullptr, nullptr};
  } else {
    if (value > (*root)->value) {
      tree_insert(&(*root)->right, value);
    }
    if (value < (*root)->value) {
      tree_insert(&(*root)->left, value);
    }
  }
}

void tree_print(TreeNode *root, std::string prefix) {
  const bool i_am_first_of_two = *prefix.rbegin() == '+';
  std::string new_prefix = prefix;
  *new_prefix.rbegin() = i_am_first_of_two ? '|' : ' ';
  std::cout << prefix << root->value << "\n";
  if (root->left && root->right) {
    tree_print(root->left, new_prefix + '+');
    tree_print(root->right, new_prefix + '`');
  } else if (root->left) {
    tree_print(root->left, new_prefix + '`');
  } else if (root->right) {
    tree_print(root->right, new_prefix + '`');
  }
}
