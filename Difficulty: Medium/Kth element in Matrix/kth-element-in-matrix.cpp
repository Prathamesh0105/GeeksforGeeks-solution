class Solution {
  public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), l = matrix[0][0], r = matrix[n-1][n-1];
        while (l < r) {
            int m = l + (r - l) / 2, cnt = 0;
            for (int i = 0, j = n - 1; i < n; ++i) {
                while (j >= 0 && matrix[i][j] > m) --j;
                cnt += j + 1;
            }
            if (cnt < k) l = m + 1;
            else r = m;
        }
        return l;
    }
};