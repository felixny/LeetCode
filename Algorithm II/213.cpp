// 213. House Robber II

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int rob(vector<int>& nums) {
      if (nums.size() == 1) return nums[0];
      return max(rob(nums,0,nums.size()-1), rob(nums,1,nums.size()));
  }

 private:
  int rob(vector<int>& nums, int start, int end) {
    int prev2 = 0, prev1 = 0, sum = 0;
    for (int i = start; i < end; i++) {
      sum = max(prev2 + nums[i], prev1);
      // update
      prev2 = prev1;
      prev1 = sum;
    }
    return sum;
  }
};
