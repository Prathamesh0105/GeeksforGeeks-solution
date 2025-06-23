class Solution {
public:
    string addString(string &s1, string &s2) {
        int i = s1.length() - 1, j = s2.length() - 1, carry = 0;
        string res = "";
        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;
            if (i >= 0) sum += (s1[i--] - '0');
            if (j >= 0) sum += (s2[j--] - '0');
            res.push_back(sum % 10 + '0');
            carry = sum / 10;
        }
        while (!res.empty() && res.back() == '0') res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
    string minSum(vector<int> &arr) {
        vector<int> count(10, 0);
        for (int num : arr) count[num]++;
        string s1 = "", s2 = "";
        bool firstNum = true;
        for (int digit = 0; digit < 10; digit++) {
            while (count[digit]--) {
                if (firstNum) {
                    if (!(s1.empty() && digit == 0)) s1.push_back(digit + '0');
                    firstNum = false;
                } else {
                    if (!(s2.empty() && digit == 0)) s2.push_back(digit + '0');
                    firstNum = true;
                }
            }
        }
        if (s1.empty()) s1 = "0";
        if (s2.empty()) s2 = "0";
        return addString(s1, s2);
    }
};