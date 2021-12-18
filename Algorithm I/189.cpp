// 189. Rotate Array

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> rotate(vector<int>& nums, int k) {
  /* if (nums.size() < k) {
    return nums;
  } */

  int sublength = nums.size() - k;
  if (sublength < 0) {
    sublength = nums.size() - 1;
  }

  // cout << sublength << endl;
  vector<int> temp;

  for (int i = sublength; i < nums.size(); i++) {
    temp.push_back(nums[i]);
    // cout << nums[i] << endl;
  }

  /* for (int i = 0; i < temp.size(); i++){
      cout << temp[i];
  } */

  vector<int> def;
  for (int i = 0; i < sublength; i++) {
    def.push_back(nums[i]);
  }

  temp.insert(temp.end(), def.begin(), def.end());

  for (int i = 0; i < temp.size(); i++) {
    cout << temp[i] << " ";
  }

  cout << endl;

  // nums = temp;
  return temp;
}

void rotate1(vector<int>& nums, int k) {
  int n = nums.size();

  vector<int> ans(n);

  for (int i = 0; i < n; ++i) {
    ans[(i + k) % n] = nums[i];
  }

  for (int i = 0; i < n; ++i) {
    nums[i] = ans[i];
  }
}

void rotates(vector<int>& nums, int k) {
  /* if (nums.size() < k) {
    return nums;
  } */

  int sublength = nums.size() - k;
  if (sublength < 0) {
    sublength = nums.size() - 1 + k;
  }

  // cout << sublength << endl;
  vector<int> temp;

  for (int i = sublength; i < nums.size(); i++) {
    temp.push_back(nums[i]);
    // cout << nums[i] << endl;
  }

  /* for (int i = 0; i < temp.size(); i++){
      cout << temp[i];
  } */

  vector<int> def;
  for (int i = 0; i < sublength; i++) {
    def.push_back(nums[i]);
  }

  temp.insert(temp.end(), def.begin(), def.end());

  /* for (int i = 0; i < temp.size(); i++) {
    cout << temp[i] << " ";
  }

  cout << endl; */

  nums = temp;
  // return temp;
}

void rotate2(vector<int>& nums, int k) {
  reverse(nums.begin(), nums.end());
  reverse(nums.begin(), nums.begin() + k);
  reverse(nums.begin() + k, nums.end());
}

int main() {
  vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
  vector<int> nums1 = {-1, -100, 3, 99};
  vector<int> nums2 = {-1};
  vector<int> nums4 = {1};
  vector<int> nums5 = {1, 2};
  vector<int> nums6 = {1, 2, 3, 4, 5, 6};

  rotate(nums, 3);
  rotate(nums1, 2);
  rotate(nums2, 2);
  rotate(nums4, 2);
  rotate(nums5, 3);
  rotate(nums6, 11);
}