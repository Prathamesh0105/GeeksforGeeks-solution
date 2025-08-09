
class Solution {
 public:
  int getLongestPrefix(string &s) {
    int n = s.length();
    if (n <= 1) {
      return -1;
    }

    // 1. Compute the Z-array for the string s.
    // Z[i] is the length of the longest common prefix between s and the suffix of s starting at i.
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
      if (i <= r) {
        z[i] = min(r - i + 1, z[i - l]);
      }
      while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
        z[i]++;
      }
      if (i + z[i] - 1 > r) {
        l = i;
        r = i + z[i] - 1;
      }
    }

    // 2. Find the longest periodic proper prefix.
    // We iterate from the longest possible prefix length downwards.
    for (int len = n - 1; len >= 1; len--) {
      // A prefix of length 'len' is periodic if the suffix of length n-len
      // matches the prefix of length n-len.
      // This is equivalent to checking if Z[len] is at least n - len.
      if (z[len] >= n - len) {
        // Since we are iterating from largest to smallest len,
        // the first one we find is the answer.
        return len;
      }
    }

    // 3. If no such prefix is found.
    return -1;
  }
};