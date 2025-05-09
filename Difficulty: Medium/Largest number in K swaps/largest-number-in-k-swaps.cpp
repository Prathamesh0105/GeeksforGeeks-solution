//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
  public:
    string res;

    void dfs(string &str, int k, int pos) {
        if (k == 0) return;

        char maxChar = *max_element(str.begin() + pos, str.end());
        if (maxChar != str[pos]) k--;

        for (int i = str.size() - 1; i >= pos; i--) {
            if (str[i] == maxChar) {
                swap(str[i], str[pos]);
                if (str > res) res = str;
                dfs(str, k, pos + 1);
                swap(str[i], str[pos]);
            }
        }
    }

    string findMaximumNum(string &str, int k) {
        res = str;
        dfs(str, k, 0);
        return res;
    }
};



//{ Driver Code Starts.

int main() {
    int t, k;
    string str;

    cin >> t;
    while (t--) {
        cin >> k >> str;
        Solution ob;
        cout << ob.findMaximumNum(str, k) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends