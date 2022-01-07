// 435. Non-overlapping intervals
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    if (intervals.empty()) return 0;

    // sort including negative numbers
    sort(begin(intervals), end(intervals),
         [](const auto& a, const auto& b) { return a[1] < b[1]; });

    int ans = 0;
    int currentEnd = intervals[0][1];

    for (int i = 1; i < intervals.size(); i++) {
      // compare start and end
      if (intervals[i][0] >= currentEnd) {
        currentEnd = intervals[i][1];
      } else {
        ans++;
      }
    }
    return ans;
  }
};

int main() {
  vector<vector<int>> intervals1 = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
  vector<vector<int>> intervals2 = {{1, 2}, {1, 2}, {1, 2}, {1, 2}};
  vector<vector<int>> intervals3 = {{1, 2}, {2, 3}};

  cout << Solution().eraseOverlapIntervals(intervals1) << endl;
  cout << Solution().eraseOverlapIntervals(intervals2) << endl;
  cout << Solution().eraseOverlapIntervals(intervals3) << endl;
  return 0;
}