class Solution {
public:
    int cntCoprime(vector<int>& arr) {
        int M = *max_element(arr.begin(), arr.end());

        vector<int> freq(M + 1, 0);
        for (int x : arr) freq[x]++;

        vector<int> multiples(M + 1, 0);
        for (int i = 1; i <= M; ++i) {
            for (int j = i; j <= M; j += i) {
                multiples[i] += freq[j];
            }
        }

        vector<long long> dp(M + 1, 0);
        for (int i = M; i >= 1; --i) {
            long long c = multiples[i];
            dp[i] = c * (c - 1) / 2;
            for (int k = 2 * i; k <= M; k += i) {
                dp[i] -= dp[k];
            }
        }

        return (int)dp[1];
    }
};
