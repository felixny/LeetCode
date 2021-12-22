// 66. Plus One
#include <climits>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> plusOne1(vector<int>& digits) {
  for (int i = 0; i <= digits.size(); i++) {
    if (digits[i] == digits.size()) {
      digits[i]++;
    }
  }

  for (int i = 0; i < digits.size(); i++){
      cout << digits[i] << endl;
  }
  
  return digits;
}

vector<int> plusOne(vector<int>& digits) {
    for (int i=digits.size(); i--; digits[i] = 0)
        if (digits[i]++ < 9)
            return digits;
    digits[0]++;
    digits.push_back(0);
    return digits;
}

int main() { 
    vector<int> d = {1,2,3};

    plusOne(d);
    
    return 0; }