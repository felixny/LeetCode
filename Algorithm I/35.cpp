// 35. Search Insert Position

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int searchInsert(vector<int>& nums, int target) {
  int low = 0;
  int high = nums.size() - 1;
  int mid;
  while (low <= high) {
    mid = (low + high) / 2;
    if (nums[mid] == target) return mid;
    // lower half
    else if (nums[mid] > target)
      high = mid - 1;
    // higher half
    else
      low = mid + 1;
  }

  std::vector<int>::iterator it1 =
      std::lower_bound(nums.begin(), nums.end(),
                       target);  // find proper position in descending order
  nums.insert(it1, target);      // insert before iterator it

  for (int i = 0; i < nums.size(); i++) {
    cout << nums.at(i) << endl;
  }

  // find the position of element in the vector.
  auto it2 = find(nums.begin(), nums.end(), target);
  
  if (it2 != nums.end()) {
    // calculating the index target
    mid = it2 - nums.begin();
  }

  // cout << index << endl;

  return mid;
}

int main() {
  vector<int> nums = {-1, 0, 3, 5, 9, 12};

  // cout << searchInsert(nums, 9) << endl;
  cout << searchInsert(nums, 11) << endl;

  return 0;
}
