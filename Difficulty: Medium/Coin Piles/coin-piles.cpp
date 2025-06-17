class Solution {
public:
    int minimumCoins(vector<int>& a, int k) {
        sort(a.begin(), a.end());
        int n = a.size(), t = accumulate(a.begin(), a.end(), 0), res = t, w = 0, p = 0, e = 0;
        for (int s = 0; s < n; s++) {
            while (e < n && a[e] - a[s] <= k) w += a[e++];
            int r = max(0, (t - p - w) - (n - e) * (a[s] + k));
            res = min(res, p + r);
            if (e == s) e++; else w -= a[s];
            p += a[s];
        }
        return res;
    }
};