// 986. Interval List Intersections

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList,
                                           vector<vector<int>>& secondList) {
    vector<vector<int>> result;
    int Aptr = 0, Bptr = 0;
    int sizeA = firstList.size();
    int sizeB = secondList.size();
    vector<int> temp(2);

    while (Aptr < sizeA && Bptr < sizeB) {
      if (secondList[Bptr][0] <= firstList[Aptr][1] &&
          firstList[Aptr][0] <= secondList[Bptr][1]) {
        temp[0] = max(firstList[Aptr][0], secondList[Bptr][0]);
        temp[1] = min(firstList[Aptr][1], secondList[Bptr][1]);
        result.push_back(temp);
      }
      if (firstList[Aptr][1] > secondList[Bptr][1])
        Bptr += 1;
      else
        Aptr += 1;
    }

    return result;
  }
};

int main() { return 0; }