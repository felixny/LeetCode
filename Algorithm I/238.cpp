// 283. Move Zeroes
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void moveZeroes(vector<int>& nums) {
  int count = 0;
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] != 0) {
      // replace
      nums[count++] = nums[i];
    }
  }
  //cout << count << endl;
  while (count < nums.size()) {
    nums[count++] = 0;
  }
}

int main(){
    vector<int> a = {0,1,0,3,12};
    vector<int> b = {0};

    moveZeroes(a);
    moveZeroes(b);

    return 0;
}