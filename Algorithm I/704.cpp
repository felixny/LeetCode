// 704. Binary Search

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target) {
  int low = 0;
  int high = nums.size() - 1;
  int mid;
  while (low <= high){
      mid = (low+high)/2;
      if (nums[mid] == target) return mid;
      // lower half
      else if (nums[mid] > target) high = mid - 1;
      // higher half
      else low = mid +1;
  }
  return -1;

}

int main() {
  vector<int> nums = {-1, 0, 3, 5, 9, 12};

  cout << search(nums, 9) << endl;

  return 0;
}
