// 47. Permutations II

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    backtrack(nums, result, 0);
    return result;
  }

 private:
  void backtrack(vector<int>& nums, vector<vector<int>>& result, int begin) {
    if (begin >= nums.size()) {
      result.push_back(nums);
    } else {
      unordered_set<int> s;
      for (int i = begin; i < nums.size(); i++) {
        if (s.count(nums[i])) continue;
        s.insert(nums[i]);
        swap(nums[begin], nums[i]);
        backtrack(nums, result, begin + 1);
        swap(nums[begin], nums[i]);
      }
    }
  }
};