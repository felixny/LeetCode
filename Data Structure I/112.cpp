// 112. Path Sum

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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;

        targetSum -= root->val;

        // root is a leaf node
        if (root->right == nullptr && root->left == nullptr){
            return (targetSum == 0);
        }

        return hasPathSum(root->left,targetSum) || hasPathSum(root->right,targetSum);
    }
};