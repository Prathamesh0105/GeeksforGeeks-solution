//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        unordered_map<int, int> prefixFirstIndex;
        int prefixSum = 0, maxLength = 0;

        for (int index = 0; index < arr.size(); ++index) {
            prefixSum += (arr[index] > k ? 1 : -1);

            if (prefixSum > 0) {
                maxLength = index + 1;
            } else {
                if (!prefixFirstIndex.count(prefixSum))
                    prefixFirstIndex[prefixSum] = index;

                if (prefixFirstIndex.count(prefixSum - 1))
                    maxLength = max(maxLength, index - prefixFirstIndex[prefixSum - 1]);
            }
        }

        return maxLength;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        int k = stoi(input);

        Solution ob;
        cout << ob.longestSubarray(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends