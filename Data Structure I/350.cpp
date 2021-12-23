// 350. Intersection of Two Arrays II
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

    if (nums1.size() > nums2.size()){
        swap(nums1,nums2);
    }
    map<int,int> record;
    for (int i = 0; i < nums1.size(); i++){
        record[nums1[i]] += 1;
    }

    vector<int> result;
    for (int i = 0; i < nums2.size(); i++){
        if (record[nums2[i]] > 0){
            result.push_back(nums2[i]);
            record[nums2[i]]--;
        }
    }

    return result;

}

int main() {
  vector<int> nums = {1, 2, 3, 1};
  vector<int> nums1 = {1, 2, 3, 4};
  vector<int> nums2 = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};



  return 0;
}