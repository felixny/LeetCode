// 231. Power of Two

class Solution {
 public:
  bool isPowerOfTwo(int n) {
    bool f = false;
    while (n != 0) {
      if (f)
        return false;
      else
        f = n & 1;
      n = n >> 1;
    }
    return f;
  }
};
