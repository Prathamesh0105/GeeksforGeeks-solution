class Solution {
  public:
    bool validgroup(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        if(n%k)return false;
        sort(arr.begin(),arr.end());
        unordered_map<int,int>mp;
        for(int &num:arr)mp[num]++;
        for (int &num:arr){
            int count=mp[num];
            if(count==0)continue;
            
                // Try to build k consecutive numbers starting from 'start'
                for(int j=0;j<k;j++){
                    int curr=num+j;
                    if(mp[curr]==0)return false;
                    mp[curr]--;
                }
        }
        return true;
    }
};