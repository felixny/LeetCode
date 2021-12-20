// 167. Two Sum II - Input Array Is Sorted

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
  int i = 0;
  int j = numbers.size() - 1;
  while (i < j){
      int sum = numbers[i] + numbers[j];
      if (sum == target){
          break;
      }
      else if (sum < target){
          i++;
      } else{
          j--;
      }
  }
  return {i+1,j+1};

}

int main() {
  vector<int> numbers = {2, 7, 11, 15};

  twoSum(numbers,9);

  
  return 0;
}