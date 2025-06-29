class Solution {
  public:
    int splitArray(vector<int>& arr, int k) {
        // code here
        int lo=*max_element(arr.begin(),arr.end());
        int high=accumulate(arr.begin(),arr.end(),0);
        
        int ans=-1;
        
        while(lo<=high){
            int mid=lo+(high-lo)/2;
            int part=1;
            int sum=0;
            for(int i=0;i<arr.size();i++){
                if(sum+arr[i]>mid){
                    part++;
                    sum=arr[i];
                }
                else sum+=arr[i];
            }
            if(part<=k){
                ans=mid;
                high=mid-1;
            }
            else {
                lo=mid+1;
            }
        }
        return ans;
    }
};