class Solution {
  public:
    string addStrings(string a, string b) {
        if (a.size() < b.size()) swap(a, b);
        int carry = 0, n = a.size(), m = b.size();
        string res = "";
        for (int i = 0; i < m; ++i) {
            int s = (a[n - 1 - i] - '0') + (b[m - 1 - i] - '0') + carry;
            res = char(s % 10 + '0') + res;
            carry = s / 10;
        }
        for (int i = m; i < n; ++i) {
            int s = (a[n - 1 - i] - '0') + carry;
            res = char(s % 10 + '0') + res;
            carry = s / 10;
        }
        if (carry) res = char(carry + '0') + res;
        return res;
    }

    bool check(string &s, int i, int l1, int l2) {
        string x = s.substr(i, l1), y = s.substr(i + l1, l2);
        if ((x[0] == '0' && l1 > 1) || (y[0] == '0' && l2 > 1)) return false;
        string sum = addStrings(x, y);
        int l3 = sum.size();
        if (i + l1 + l2 + l3 > s.size()) return false;
        if (sum != s.substr(i + l1 + l2, l3)) return false;
        if (i + l1 + l2 + l3 == s.size()) return true;
        return check(s, i + l1, l2, l3);
    }

    bool isSumString(string &s) {
        int n = s.size();
        for (int l1 = 1; l1 < n; ++l1)
            for (int l2 = 1; l1 + l2 < n; ++l2)
                if (check(s, 0, l1, l2)) return true;
        return false;
    }
};