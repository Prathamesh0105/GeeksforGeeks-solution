//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int findMissing(vector<int> &arr) {
        // code here
        int length = arr.size();
        int firstDiff = arr[1] - arr[0];
        int lastDiff = arr[length - 1] - arr[length - 2];
        int avgDiff = (arr[length - 1] - arr[0]) / length;

        int commonDiff = (firstDiff == lastDiff || firstDiff == avgDiff) ? firstDiff : lastDiff;

        if (commonDiff == 0) return arr[0];

        int left = 0, right = length - 1;

        while (left <= right) {
            int midIndex = (left + right) >> 1;
            if ((arr[midIndex] - arr[0]) / commonDiff == midIndex) {
                left = midIndex + 1;
            } else {
                right = midIndex - 1;
            }
        }

        return arr[0] + left * commonDiff;
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
        Solution ob;
        cout << ob.findMissing(arr) << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends