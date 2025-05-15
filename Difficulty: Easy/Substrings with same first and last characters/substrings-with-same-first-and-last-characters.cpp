//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countSubstring(string &s) {
        // code here
        int count[26] = {0};

        for (char ch : s) {
            count[ch - 'a']++;
        }

        int result = 0;
        for (int i = 0; i < 26; i++) {
            result += count[i]; 
            result += (count[i] * (count[i] - 1)) / 2; 
        }

        return result;
    }
};


//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;

        Solution ob;

        cout << ob.countSubstring(str) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends