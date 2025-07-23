class Solution {
  public:
    int subarraySum(vector<int>& arr) {
        int n=arr.size();
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=(arr[i]*(i+1)*(n-i));
        }
        return ans;
    }
};