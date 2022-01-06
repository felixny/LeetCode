// 56. Merge Intervals

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> merged;

    for (auto& vec : intervals) {
      for (auto ele : vec) {
        cout << ele << " ";
      }
      cout << endl;
    }

    for (auto temp : intervals) {
      // cout << temp[0] << " ";

      if (merged.empty() || merged.back()[1] < temp[0]) {
        merged.push_back(temp);

        /* cout << merged.back()[0] << " ";
        cout << merged.back()[1] << " "; */

      } else {
        merged.back()[1] = max(merged.back()[1], temp[1]);
      }
    }

    for (auto& vec : merged) {
      for (auto ele : vec) {
        cout << ele << " ";
      }
      cout << endl;
    }
    return merged;
  }
};

int main() {
  vector<vector<int>> nums{{1, 3}, {2, 6}, {8, 10}, {15, 18}};

  Solution().merge(nums);
}