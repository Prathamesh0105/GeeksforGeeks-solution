class Solution {
public:
    int maxSum(string s) {
        int n = s.size();
        if (n < 2) return 0;

        vector<int> d = manacherOdd(s);

        vector<int> maxEnd(n, 0);   // best palindrome length ending exactly at i
        vector<int> maxStart(n, 0); // best palindrome length starting exactly at i

        // Sweep left->right to compute maxEnd
        priority_queue<pair<int,int>> pq; // {B, R}
        int centerIdx = 0;
        for (int e = 0; e < n; e++) {
            while (centerIdx < n && centerIdx <= e) {
                int c = centerIdx;
                int B = 1 - 2 * c;           // contribution constant
                int R = c + d[c] - 1;        // rightmost end
                pq.push({B, R});
                centerIdx++;
            }
            while (!pq.empty() && pq.top().second < e) pq.pop();
            if (!pq.empty()) {
                maxEnd[e] = 2 * e + pq.top().first; // 2*e + B
            } else {
                maxEnd[e] = 1;
            }
        }

        // prefix maxima
        vector<int> maxPref(n);
        int cur = 0;
        for (int i = 0; i < n; i++) {
            if (maxEnd[i] > cur) cur = maxEnd[i];
            maxPref[i] = cur;
        }

        // Sweep right->left to compute maxStart
        priority_queue<pair<int,int>> pq2; // {C, L}
        int centerIdx2 = n - 1;
        for (int sIdx = n - 1; sIdx >= 0; sIdx--) {
            while (centerIdx2 >= 0 && centerIdx2 >= sIdx) {
                int c = centerIdx2;
                int C = 2 * c + 1;
                int L = c - d[c] + 1;
                pq2.push({C, L});
                centerIdx2--;
            }
            while (!pq2.empty() && pq2.top().second > sIdx) pq2.pop();
            if (!pq2.empty()) {
                maxStart[sIdx] = -2 * sIdx + pq2.top().first;
            } else {
                maxStart[sIdx] = 1;
            }
        }

        // suffix maxima
        vector<int> maxSuff(n);
        cur = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (maxStart[i] > cur) cur = maxStart[i];
            maxSuff[i] = cur;
        }

        // combine non-overlapping
        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            ans = max(ans, maxPref[i] + maxSuff[i + 1]);
        }
        return ans;
    }

private:
    vector<int> manacherOdd(const string &s) {
        int n = s.size();
        vector<int> d(n);
        int l = 0, r = -1;
        for (int i = 0; i < n; i++) {
            int k = 1;
            if (i <= r) k = min(d[l + r - i], r - i + 1);
            while (i - k >= 0 && i + k < n && s[i - k] == s[i + k]) k++;
            d[i] = k;
            if (i + k - 1 > r) {
                l = i - k + 1;
                r = i + k - 1;
            }
        }
        return d;
    }
};