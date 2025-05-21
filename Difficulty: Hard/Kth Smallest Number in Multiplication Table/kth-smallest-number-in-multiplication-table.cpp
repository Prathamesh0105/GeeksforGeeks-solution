class Solution {
  public:
    int countLessEqual(int x, int m, int n) {
        int count = 0;
        for (int i = 1; i <= m; ++i) {
            count += min(x / i, n);
        }
        return count;
    }

    int kthSmallest(int m, int n, int k) {
        int low = 1, high = m * n;
        while (low < high) {
            int mid = (low + high) / 2;
            if (countLessEqual(mid, m, n) < k)
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }
};
