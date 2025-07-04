class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        int cnt = 0;
        int l = 0; int r = 0;
        unordered_map<int, int>mpp;
        while(r<n){
            mpp[arr[r]]++;
            while(mpp.size()>k){
                mpp[arr[l]]--;
                if(mpp[arr[l]]==0) mpp.erase(arr[l]);
                l++;
            }
            if(mpp.size()<=k){
                cnt += (r-l+1);
            }
            r++;
        }
        return cnt;
    }
};

