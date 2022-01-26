// 40. Combination Sum II

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

// TLE
class Solution {
 public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    sort(candidates.begin(), candidates.end());
    vector<int> current_result;
    backtrack(candidates, target, result, current_result, 0);
    return result;
  }

 private:
  void backtrack(vector<int>& candidates, int target,
                 vector<vector<int>>& result, vector<int>& current_result,
                 int index) {
    // basecase
    if (target == 0) {
      auto it = find(result.begin(), result.end(), current_result);
      // couldn't find in vector
      if (it == result.end()) result.push_back(current_result);
      return;
    }
    // decisions
    for (int i = index; i < candidates.size() && target >= candidates[i]; i++) {
      current_result.push_back(candidates[i]);
      int newtarget = target - candidates[i];
      index = i + 1;
      backtrack(candidates, newtarget, result, current_result, index);
      current_result.pop_back();
    }
  }
};

// accepted
class Solution {
 public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    sort(candidates.begin(), candidates.end());
    vector<int> current_result;
    dfs(candidates, target, result, current_result, 0);
    return result;
  }

 private:
  void dfs(vector<int>& candidates, int target, vector<vector<int>>& result,
           vector<int>& current_result, int index) {
    // base case
    if (target == 0) {
      result.push_back(current_result);
    }
    // decisions
    for (int i = index; i < candidates.size(); i++) {
      int num = candidates[i];
      if (num > target) return;
      if (i > index && candidates[i] == candidates[i - 1]) continue;
      current_result.push_back(num);
      dfs(candidates, target - num, result, current_result, i + 1);
      current_result.pop_back();
    }
  }
};
