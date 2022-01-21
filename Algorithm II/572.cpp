// 572. Subtree of Another Tree

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
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
  bool isSubtree(TreeNode *root, TreeNode *subRoot) {
      if (root == nullptr && subRoot == nullptr) return true;
      if (root == nullptr || subRoot == nullptr) return false;
      if (root->val == subRoot->val && isSameTree(root,subRoot)) return true;
      return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
  }

 private:
  bool isSameTree(TreeNode *s, TreeNode *t) {
    if (s == nullptr && t == nullptr) return true;
    if (s == nullptr || t == nullptr || s->val != t->val) return false;
    return (isSameTree(s->left, t->left) && isSameTree(s->right, t->right));
  }
};