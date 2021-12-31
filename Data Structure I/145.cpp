// 145. Binary Tree Postorder Traversal

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <stack>

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
    vector<int> postorderTraversal(TreeNode* root) {
      vector<int> ans;
        stack<TreeNode*> stk;
        //Postorder(LRD) --> Reverse(DRL) --> DRL is similar to Preorder(DLR)
        while(root or !stk.empty()){
            while(root){
                ans.push_back(root->val);
                stk.push(root);
                root=root->right;
            }
            root= stk.top();
            stk.pop();
            root=root->left;
        }
        //Reverse(DRL)
        reverse(ans.begin(),ans.end());
        return ans;
    }
};