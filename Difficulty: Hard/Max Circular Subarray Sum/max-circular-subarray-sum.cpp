class Solution {
public:
    int maxCircularSum(vector<int> &arr) {
        int n=arr.size();
        int totalSum=accumulate(arr.begin(),arr.end(),0);
        int currMax=arr[0],maxSum=arr[0];
        int currMin=arr[0],minSum=arr[0];
        for(int i=1;i<n;i++){
            currMax=max(arr[i],currMax+arr[i]);
            maxSum=max(maxSum,currMax);
            currMin=min(arr[i],currMin+arr[i]);
            minSum=min(minSum,currMin);
        }
        if(maxSum<0) return maxSum;
        return max(maxSum,totalSum-minSum);
    }
};