//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    vector<int> findSmallestRange(vector<vector<int>>& arr) {
        int k = arr.size();

        // Min-heap to store elements as {value, row, col}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;

        int maxVal = INT_MIN;

        // Initialize heap with the first element of each list
        for (int i = 0; i < k; ++i) {
            int val = arr[i][0];
            minHeap.push({val, i, 0});
            maxVal = max(maxVal, val);
        }

        int rangeStart = 0, rangeEnd = INT_MAX;

        while (true) {
            auto curr = minHeap.top();
            minHeap.pop();

            int minVal = curr[0];
            int row = curr[1];
            int col = curr[2];

            // Update the best range
            if (maxVal - minVal < rangeEnd - rangeStart) {
                rangeStart = minVal;
                rangeEnd = maxVal;
            }

            // If there's a next element in the same list, push it
            if (col + 1 < arr[row].size()) {
                int nextVal = arr[row][col + 1];
                minHeap.push({nextVal, row, col + 1});
                maxVal = max(maxVal, nextVal);
            } else {
                // We reached the end of one list
                break;
            }
        }

        return {rangeStart, rangeEnd};
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> arr(k, vector<int>(n));

        for (int i = 0; i < k; i++)
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];

        Solution obj;
        vector<int> range = obj.findSmallestRange(arr);
        cout << range[0] << " " << range[1] << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends