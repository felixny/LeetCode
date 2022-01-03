// 98. Validate Binary Search Tree

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  bool isValidBST(TreeNode* root) {
      return helper(root,nullptr,nullptr);
  }

  bool helper(TreeNode* root, TreeNode* left, TreeNode* right) {
    if (root == nullptr) return true;

    // if root value is greater than right value then should be false
    if ((right && root->val >= right->val) || (left && root->val <= left->val))
      return false;
    
    return helper(root->left, left, root) && helper(root->right, root, right);
  }
};