// 121. Best Time to Buy and Sell Stock
#include <limits.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int minPrice = INT_MAX;
    int maxProfit = 0;

    for (int i = 0; i < prices.size(); i++) {
      if (prices[i] < minPrice) {
        minPrice = prices[i];
      } else if (prices[i] - minPrice > maxProfit) {
        maxProfit = prices[i] - minPrice;
      }
    }

    return maxProfit;
  }
};

int main() {
  vector<int> nums = {7, 1, 5, 3, 6, 4};

  cout << Solution().maxProfit(nums) << endl;
}