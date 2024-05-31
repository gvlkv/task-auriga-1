#ifndef ALGO11_H_
#define ALGO11_H_

#include <string>

struct TreeNode {
  int value;
  TreeNode *left;
  TreeNode *right;
};

TreeNode *find_closest(TreeNode *root, int x, TreeNode *last_left = nullptr,
                       TreeNode *last_right = nullptr);
void tree_insert(TreeNode **root, int value);
void tree_print(TreeNode *root, std::string prefix = "`");
#endif // ALGO11_H_
