// 198. House Robber

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int rob(vector<int>& nums) {
    int rob = 0;
    int norob = 0;
    for (int i = 0; i < nums.size(); i++) {
      int newRob = norob + nums[i];
      int newnoRob = max(norob, rob);
      rob = newRob;
      norob = newnoRob;
    }
    return max(norob, rob);
  }
};

int main(){

    vector<int> nums = {1,2,3,1};
    cout << Solution().rob(nums) << endl;
    return 0;
}