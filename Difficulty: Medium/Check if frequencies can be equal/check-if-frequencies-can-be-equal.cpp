class Solution {
public:
    bool sameFreq(string& s) {
        vector<int> freq(26);
        for (char c : s) freq[c - 'a']++;
        unordered_map<int, int> m;
        for (int f : freq) if (f) m[f]++;
        if (m.size() == 1) return true;
        if (m.size() == 2) {
            auto a = m.begin(), b = next(a);
            int f1 = a->first, c1 = a->second;
            int f2 = b->first, c2 = b->second;
            return (f1 == 1 && c1 == 1) || (f2 == 1 && c2 == 1) ||
                  (abs(f1 - f2) == 1 && ((f1 > f2 && c1 == 1) || (f2 > f1 && c2 == 1)));
        }
        return false;
    }
};