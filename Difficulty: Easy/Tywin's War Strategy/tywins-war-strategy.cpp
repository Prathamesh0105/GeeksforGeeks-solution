class Solution {
  public:
    int minSoldiers(vector<int>& arr, int k) {
        // code here
        for(int i = 0;i<arr.size();i++){
            arr[i] = arr[i] + k;
            if(arr[i]%k==0) arr[i] = 0;
            else arr[i] = k - (arr[i]%k);
        }
        
        sort(arr.begin(), arr.end());
        
        int ans = 0;
        int m = (arr.size()+1)/2;
        
        for(int i = 0;i<m;i++){
            ans += arr[i];
        }
        
        return ans;
    }
};