class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        int var = 0, ans = 0;
        vector<int> store{-1};
        
        for(int i = 0; i < arr.size(); i++)
        {
            var += (arr[i]>k ? 1 : -1);
            
            if(var>0) ans = i+1;
            else if(1-var<store.size()) ans = max(ans,i-store[1-var]);
            
            if(store.size()==-var) store.push_back(i);
        }
        
        return ans;
    }
};