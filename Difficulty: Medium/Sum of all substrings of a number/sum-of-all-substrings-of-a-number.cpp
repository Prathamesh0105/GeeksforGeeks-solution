class Solution {
  public:
    int sumSubstrings(string &s) {
        int n = s.length();
        long long result = 0;
        long long prev_sum = 0;
        const int MOD = 1e9 + 7; 

        for (int i = 0; i < n; ++i) {
            int digit = s[i] - '0';
            prev_sum = prev_sum * 10 + (i + 1) * digit;
            result += prev_sum;
        }

        return result;
    }
};
