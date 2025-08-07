class Solution {
  public:
    int minDifference(vector<string> &arr) {
        // code here
         int n = arr.size();
        vector<long long> tm;

        for (string ch : arr) {
            int hr = stoi(ch.substr(0, 2));
            int min = stoi(ch.substr(3, 2));
            int sec = stoi(ch.substr(6, 2));
            long long total = hr * 3600 + min * 60 + sec;
            tm.push_back(total);
        }

        sort(tm.begin(), tm.end());

        long long ans = LLONG_MAX;

        for (int i = 1; i < n; i++) {
            long long diff = tm[i] - tm[i - 1];
            ans = min(ans, diff);
        }

        // Wrap-around case (e.g., 23:59:59 and 00:00:01)
        long long wrapDiff = 86400 - tm[n - 1] + tm[0];
        ans = min(ans, wrapDiff);

        return (int)ans;
    }
};

