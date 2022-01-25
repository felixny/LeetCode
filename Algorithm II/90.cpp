// 90. Subsets II

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

// recursive backtracking
class Solution {
  void backtrack(vector<vector<int>>& result, vector<int>& subset,
                 vector<int>& nums, int start) {
    result.push_back(subset);
    for (int i = start; i < nums.size(); i++) {
      if (i > start && nums[i] == nums[i - 1]) continue;
      subset.push_back(nums[i]);
      backtrack(result, subset, nums, i + 1);
      subset.pop_back();
    }
  }

 public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> current;
    sort(nums.begin(), nums.end());
    backtrack(result, current, nums, 0);

    return result;
  }
};
