class Solution {
  public:
    int totalElements(vector<int> &arr) {
        map<int,int> mp;
        int ans = 1;
        int l=0,r=0;
        while(r<arr.size()){
            mp[arr[r]]++;
            while(mp.size()>2){
                mp[arr[l]]--;
                if(mp[arr[l]] == 0){
                    mp.erase(mp.find(arr[l]));
                }
                l++;
            }
            ans = max(ans,r-l+1);
            r++;
        }
        
        return ans;
    }
};