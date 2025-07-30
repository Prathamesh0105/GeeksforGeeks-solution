class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        // code here
        map<int,int> mp;
        int sum=0;
        int ans=0;
        for(int i:arr){
            sum+=i;
            if(sum==k)
            ans++;
            ans+=mp[sum];
            mp[sum+k]++;
        }
        return ans;
    }
};