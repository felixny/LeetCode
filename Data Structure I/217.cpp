// 217. Contains Duplicate

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool containsDuplicate(vector<int>& nums) {
  sort(nums.begin(), nums.end());
  for (int i = 0; i < nums.size() - 1; i++) {
    if (nums[i] == nums[i + 1]) {
      cout << "true" << endl;
      return true;
    }
  }
  cout << "false" << endl;
  return false;
}

int main() {
  vector<int> nums = {1, 2, 3, 1};
  vector<int> nums1 = {1, 2, 3, 4};
  vector<int> nums2 = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};

  cout << containsDuplicate(nums) << endl;
  cout << containsDuplicate(nums1) << endl;
  cout << containsDuplicate(nums2) << endl;
  
  return 0;
}