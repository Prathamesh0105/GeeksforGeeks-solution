//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findSubString(string& s) {
        unordered_set<char> all(s.begin(), s.end());
        int n = s.size(), i = 0, j = 0, d = all.size(), c = 0, res = n;
        vector<int> freq(256, 0);
        while (j < n) {
            if (++freq[s[j++]] == 1) c++;
            while (c == d) {
                res = min(res, j - i);
                if (--freq[s[i++]] == 0) c--;
            }
        }
        return res;
    }
};


//{ Driver Code Starts.
//      Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends