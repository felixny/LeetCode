// 69. Sqrt(x)

#include <math.h>

#include <climits>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int mySqrt(int x) {
  int low = 0, high = x, mid;
  if (x < 2) return x;
  while (low < high) {
    mid = (low + high) / 2;
    if (x / mid >= mid)
      low = mid + 1;
    else
      high = mid;
  }
  return high - 1;
}

int main() { cout << mySqrt(8); }