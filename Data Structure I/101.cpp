// 101. Symmetric Tree

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
class Solution {
 public:
  bool isSymmetric(TreeNode *root) {
    if (root == nullptr) return true;

    //return recursion(root->left, root->right);

    return iterative(root);
  }

 private:
  bool recursion(TreeNode *left, TreeNode *right) {
    if (left == nullptr && right == nullptr) {
      return true;
    }

    if (left != nullptr && right != nullptr && left->val == right->val) {
      return recursion(left->left, right->right) &&
             recursion(left->right, right->left);
    }

    return false;
  }

  bool iterative(TreeNode *root) {
    stack<TreeNode *> left;
    stack<TreeNode *> right;

    left.push(root->left);
    right.push(root->right);

    while (left.size() > 0) {
      auto l = left.top();
      left.pop();
      auto r = right.top();
      right.pop();

      // stack is empty means symmetric
      if (l == nullptr && r == nullptr) {
        continue;
      }

      if (l != nullptr && r != nullptr && l->val == r->val) {
          left.push(l->left);
          right.push(r->right);
          left.push(l->right);
          right.push(r->left);
          continue;
      }
      return false;
    }
    return true;
  }
};