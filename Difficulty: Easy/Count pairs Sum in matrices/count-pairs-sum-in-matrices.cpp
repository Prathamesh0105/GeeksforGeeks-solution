class Solution {
  public:
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int x) {
        unordered_set<int> set2;
        int n = mat1.size();
        int count = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                set2.insert(mat2[i][j]);
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int required = x - mat1[i][j];
                if (set2.count(required)) {
                    count++;
                }
            }
        }

        return count;
    }
};
