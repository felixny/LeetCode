// 46. Permutations
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    vector<bool> visited(nums.size());
    vector<int> current;
    dfs(nums, result, current, visited);
    return result;
  }

 private:
  void dfs(vector<int>& nums, vector<vector<int>>& result, vector<int>& current,
           vector<bool> visited) {
    if (current.size() == nums.size()) {
      result.push_back(current);
      //return;
    }

    for (int i = 0; i < nums.size(); i++) {
      if (visited[i] == false) {
        visited[i] = true;
        current.push_back(nums[i]);
        dfs(nums, result, current, visited);
        current.pop_back();
        visited[i] = false;
      }
    }
  }
};

void print_vec(const vector<int>& vec) {
  for (int e : vec) cout << e << " ";
  cout << endl;
}

int main() {
  vector<int> nums = {1, 2, 3};
  vector<vector<int>> res = Solution().permute(nums);
  for (int i = 0; i < res.size(); i++) print_vec(res[i]);
  return 0;
}