// 75. Sort Colors

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  void sortColors(vector<int>& nums) {
    // create 0,0,0;
    vector<int> colors(3);
    for (int num : nums) {
      ++colors[num];
      cout << colors[num] << "";
    }
    cout << endl;

    for (int i = 0, curr = 0; i < colors.size(); i++) {
      for (int j = 0; j < colors[i]; j++) {
        nums[curr++] = i;
      }
    }

    for (int i = 0; i < nums.size(); i++) {
      cout << nums[i] << " ";
    }
  }
};

// Two Pointers
class Solution {
 public:
  void sortColors(vector<int>& nums) {
    int l = 0, r = nums.size() - 1, i = 0;

    while (i < r + 1) {
      if (nums[i] == 0) {
        swap(nums[i++], nums[l++]);
      } else if (nums[i] == 1) {
        i++;
      } else {
        swap(nums[i], nums[r--]);
      }
    }
  }
};

int main() {
  vector<int> nums = {2, 0, 2, 1, 1, 0};
  Solution().sortColors(nums);
}
