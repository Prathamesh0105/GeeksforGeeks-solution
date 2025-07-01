class Solution {
  public:
    int substrCount(string &s, int k) {
        int curr = 0;
        int prev = -1;
        int ans = 0;
        unordered_map<char, int> mp;

        while (curr < s.size()) {
            char ch = s[curr];
            mp[ch]++;

            while (curr - prev > k) {
                char CH = s[++prev];
                mp[CH]--;
                if (mp[CH] == 0)
                    mp.erase(CH);
            }

            if (curr - prev == k && mp.size() == k - 1)
                ans++;

            curr++;
        }

        return ans;
    }
};