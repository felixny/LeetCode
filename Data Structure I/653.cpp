// 653. Two Sum IV - Input is a BST

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
  vector<int> v;
  void helper(TreeNode *root) {
    if (root == nullptr) {
      return;
    }
    helper(root->left);
    v.push_back(root->val);
    helper(root->right);
  }
  bool findTarget(TreeNode *root, int k) {
    helper(root);
    int start = 0;
    int end = v.size() - 1;
    while (end > start) {
      if (v[start] + v[end] == k) {
        return true;
      } else if (v[start] + v[end] > k) {
        end--;
      } else {
        start++;
      }
    }
    return false;
  }
};