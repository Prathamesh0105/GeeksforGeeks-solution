class Solution {
  public:
    vector<int> printKClosest(vector<int> a, int k, int x) {
        int n = a.size(), l = 0, h = n - 1, p = -1;
        while (l <= h) {
            int m = (l + h) / 2;
            if (a[m] < x) p = m, l = m + 1;
            else h = m - 1;
        }
        int i = p, j = p + 1;
        if (j < n && a[j] == x) j++;
        vector<int> r;
        while (i >= 0 && j < n && r.size() < k)
            r.push_back(abs(a[i] - x) < abs(a[j] - x) ? a[i--] : a[j++]);
        while (i >= 0 && r.size() < k) r.push_back(a[i--]);
        while (j < n && r.size() < k) r.push_back(a[j++]);
        return r;
    }
};