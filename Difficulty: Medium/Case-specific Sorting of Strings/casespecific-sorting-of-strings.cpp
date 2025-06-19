class Solution {
public:
    string caseSort(string &s) {
        int l[26] = {0}, u[26] = {0};
        for (char c : s) (c & 32) ? l[c - 97]++ : u[c - 65]++;
        int i = 0, j = 0;
        for (char &c : s) {
            if (c & 32) {
                while (!l[i]) i++;
                c = i + 97;
                l[i]--;
            } else {
                while (!u[j]) j++;
                c = j + 65;
                u[j]--;
            }
        }
        return s;
    }
};