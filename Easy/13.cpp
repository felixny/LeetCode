// 13. Roman to Integer
#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <string>

using namespace std;

/* int romanToInt(string s) {
  // char* char_arr;

  // char roman[8] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

  string roman = {"IVXLCDM"};
  string special[6] = {"IV","IX","XL","XC","CD","CM"};
  int specialval[6] = {4,9,40,90,400,900};
  int value[8] = {1, 5, 10, 50, 100, 500, 1000};
  int sum = 0;
    int sum1 =0;
  for (int i = 0; i < roman.length(); i++) {
    for (int j = 0; j < s.length(); j++) {
      if (roman[i] == s[j]) {
        int index = s.find(roman[i]);
        int index1 = s.find(special[i]);
        sum1 += specialval[i];
        sum += value[i];
      }
    }
  }

  return sum1;
}
 */

int romanToInt(string s) {
  map<char, int> m{{'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
                   {'C', 100}, {'D', 500}, {'M', 1000}};

  int sum = 0;
  for (int i = 0; i < s.length(); i++){
      sum += m[s[i]];
      if (i > 0 && m[s[i]] > m[s[i-1]])
      sum -= 2 * m[s[i-1]];
  }
  return sum;
}

int main() {
  cout << romanToInt("III") << endl;
  cout << romanToInt("LVIII") << endl;
  cout << romanToInt("MCMXCIV") << endl;

  return 0;
}