// 415. Add Strings
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string addStrings(string num1, string num2) {
    string result;

    // length of the string
    int indexOne = num1.length() - 1;
    int indexTwo = num2.length() - 1;
    int carry = 0;

    while (indexOne >= 0 || indexTwo >= 0 || carry) {
      int v1 = indexOne >= 0 ? num1[indexOne] - '0' : 0;
      int v2 = indexTwo >= 0 ? num2[indexTwo] - '0' : 0;

      int sum = v1 + v2 + carry;
      result.push_back(sum % 10 + '0');
      carry = sum / 10;

      indexOne--;
      indexTwo--;
    }

    reverse(begin(result), end(result));

    return result;
  }
};

int main() { return 0; }