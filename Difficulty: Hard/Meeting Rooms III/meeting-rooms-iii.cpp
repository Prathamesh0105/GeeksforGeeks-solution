//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        priority_queue<int, vector<int>, greater<>> av;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> bz;
        vector<int> cnt(n);
        for (int i = 0; i < n; i++) av.push(i);
        for (auto &mt : meetings) {
            long long s = mt[0], e = mt[1];
            while (!bz.empty() && bz.top().first <= s) {
                av.push(bz.top().second);
                bz.pop();
            }
            int r;
            if (av.empty()) {
                r = bz.top().second;
                long long t = bz.top().first + (e - s);
                bz.pop();
                bz.push({t, r});
            } else {
                r = av.top();
                av.pop();
                bz.push({e, r});
            }
            cnt[r]++;
        }
        return max_element(cnt.begin(), cnt.end()) - cnt.begin();
    }
};


//{ Driver Code Starts.

int main() {
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> m;
        vector<vector<int>> meetings(m, vector<int>(2));
        for (int i = 0; i < m; i++) {
            cin >> meetings[i][0] >> meetings[i][1];
        }
        Solution ob;
        cout << ob.mostBooked(n, meetings) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends