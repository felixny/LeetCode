// 169. Majority Element
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    return nums[nums.size() / 2];
  }
};

class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    map<int, int> count;

    // iterate through vectors
    for (int e : nums) {
        // if it equals to the end
      if (count.find(e) == count.end()) {
        count[e] = 1;
      } else {
        count[e] += 1;
      }
    }

    for (auto iter = count.begin(); iter != count.end(); iter++){
        if (iter->second > nums.size()/2){
            return iter->first;
        }
    }

    return -1;
  }
};

int main() {
  vector<int> nums = {3, 2, 3};
  vector<int> nums1 = {2, 2, 2, 1, 1, 1, 2, 2};

  cout << Solution().majorityElement(nums) << endl;
  cout << Solution().majorityElement(nums1) << endl;
}