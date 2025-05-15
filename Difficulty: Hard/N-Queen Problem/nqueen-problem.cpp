//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
public:
    bool isSafe(int row, int col, vector<int> &positions) {
        for (int prevCol = 0; prevCol < col; ++prevCol) {
            int prevRow = positions[prevCol];
            if (prevRow == row || abs(prevRow - row) == abs(prevCol - col)) {
                return false;
            }
        }
        return true;
    }

    void solve(int col, int n, vector<int> &positions, vector<vector<int>> &solutions) {
        if (col == n) {
            vector<int> solution(n);
            for (int i = 0; i < n; ++i)
                solution[i] = positions[i] + 1;  
            solutions.push_back(solution);
            return;
        }

        for (int row = 0; row < n; ++row) {
            if (isSafe(row, col, positions)) {
                positions[col] = row;
                solve(col + 1, n, positions, solutions);
            }
        }
    }

    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> solutions;
        vector<int> positions(n);
        solve(0, n, positions, solutions);
        return solutions;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if (ans.size() == 0)
            cout << -1 << "\n";
        else {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++) {
                cout << "[";
                for (int u : ans[i])
                    cout << u << " ";
                cout << "] ";
            }
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends