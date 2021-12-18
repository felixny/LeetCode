// 278. First Bad Version

#include <iostream>

using namespace std;

bool isBadVersion(int version) {
  if (version) {
    true;
  }
}

// linear scan
int firstBadVersion(int n) {
  int count = 0;
  for (int i = 0; i < n; i++) {
    if (isBadVersion(n) == true) {
      count++;
    }
  }
  int output = n - count + 1;
  return output;
}

// binary search
int firstBadVersion(int n) {
  int left = 1;
  int right = n;
  while (left < right) {
    int mid = left + (right - left) / 2;
    if (isBadVersion(mid)) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  return left;
}

int main() { return 0; }