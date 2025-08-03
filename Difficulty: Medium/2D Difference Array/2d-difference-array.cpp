class Solution {
  public:
    vector<vector<int>> applyDiff2D(vector<vector<int>>& mat,
                                    vector<vector<int>>& opr) {
        // code here
        int n = mat.size();
        int m = mat[0].size();

        // Step 1: Create a diff matrix with one extra row and column
        vector<vector<int>> diff(n + 1, vector<int>(m + 1, 0));

        // Step 2: Apply each operation to diff
        for (const auto& op : opr) {
            int v = op[0];
            int r1 = op[1], c1 = op[2], r2 = op[3], c2 = op[4];

            diff[r1][c1] += v;
            if (r2 + 1 < n) diff[r2 + 1][c1] -= v;
            if (c2 + 1 < m) diff[r1][c2 + 1] -= v;
            if (r2 + 1 < n && c2 + 1 < m) diff[r2 + 1][c2 + 1] += v;
        }

        // Step 3: Horizontal prefix sums
        for (int i = 0; i < n; ++i)
            for (int j = 1; j < m; ++j)
                diff[i][j] += diff[i][j - 1];

        // Step 4: Vertical prefix sums
        for (int j = 0; j < m; ++j)
            for (int i = 1; i < n; ++i)
                diff[i][j] += diff[i - 1][j];

        // Step 5: Add diff to original matrix
        vector<vector<int>> result(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                result[i][j] = mat[i][j] + diff[i][j];

        return result;
    }
};