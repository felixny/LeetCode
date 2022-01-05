// 700. Search in a Binary Search Tree

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
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
  TreeNode *searchBST(TreeNode *root, int val) {

      if (root == nullptr) return nullptr;
      if (root->val == val) return root;

      if (root->val > val){
          return searchBST(root->left, val);
      } else {
          return searchBST(root->right, val);
      }
  }
};