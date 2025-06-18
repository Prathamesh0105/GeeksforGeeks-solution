class Solution {
public:
    vector<vector<string>> palinParts(string& s) {
        int n = s.size();
        vector<vector<bool>> d(n, vector<bool>(n));
        for (int i = 0; i < n; i++) d[i][i] = true;
        for (int i = 0; i < n - 1; i++) d[i][i + 1] = s[i] == s[i + 1];
        for (int l = 3; l <= n; l++)
            for (int i = 0; i <= n - l; i++) {
                int j = i + l - 1;
                d[i][j] = s[i] == s[j] && d[i + 1][j - 1];
            }
        vector<vector<string>> r;
        vector<string> c;
        function<void(int)> b = [&](int i) {
            if (i == n) { r.push_back(c); return; }
            for (int j = i; j < n; j++)
                if (d[i][j]) {
                    c.push_back(s.substr(i, j - i + 1));
                    b(j + 1);
                    c.pop_back();
                }
        };
        b(0);
        return r;
    }
};