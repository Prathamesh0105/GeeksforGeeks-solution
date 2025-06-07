class Solution {
  public:
    int longestCommonSum(vector<int> &a1, vector<int> &a2) {
        int n = a1.size();
        unordered_map<int, int> prefixIndex;
        int maxLen = 0, prefixSum = 0;

        for (int i = 0; i < n; i++) {
            int diff = a1[i] - a2[i];
            prefixSum += diff;

            if (prefixSum == 0) {
                maxLen = i + 1;
            }

            if (prefixIndex.find(prefixSum) != prefixIndex.end()) {
                maxLen = max(maxLen, i - prefixIndex[prefixSum]);
            } else {
                prefixIndex[prefixSum] = i;
            }
        }

        return maxLen;
    }
};
