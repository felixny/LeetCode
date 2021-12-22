// 88. Merge Sorted Array

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
  /* map<int, bool> map;

  for (int i = 0; i < m; i++) {
    map[nums1[i]] = true;
  }
  for (int i = 0; i < n; i++) {
    map[nums2[i]] = true;
  }
 */
  vector<int> merged(m + n);
  int i = 0, j = 0, k = 0;

  while (i < m && j < n) {
    if (nums1[i] < nums2[j]) {
      merged[k++] = nums1[i++];
    } else {
      merged[k++] = nums2[j++];
    }
  }

  while (i < m) {
    merged[k++] = nums1[i++];
  }

  while (j < n) {
    merged[k++] = nums2[j++];
  }

  nums1 = merged;
}

void merge1(vector<int>& nums1, int m, vector<int>& nums2, int n) {
  map<int, bool> map;

  for (int i = 0; i < m; i++) {
    map[nums1[i]] = true;
  }
  for (int i = 0; i < n; i++) {
    map[nums2[i]] = true;
  }

  vector<int> key(m+n);
  vector<bool> value;
  for (std::map<int, bool>::iterator it = map.begin(); it != map.end(); it++) {
    key.push_back(it->first);
    value.push_back(it->second);
    cout << "Key: " << it->first << endl;
    cout << "Value: " << it->second << endl;
  }

  nums1 = key;
}

int main() {
  vector<int> nums1 = {1, 2, 3, 0, 0, 0};
  vector<int> nums2 = {2, 5, 6};

  merge1(nums1,3,nums2,3);

  return 0;
}