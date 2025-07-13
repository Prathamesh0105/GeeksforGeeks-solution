class Solution {
  public:
    int nonLisMaxSum(vector<int>& arr) {
        int n=arr.size();
        vector<int> count(n,1);
        vector<int> sum(n);
        for(int i=0;i<n;i++)
            sum[i]=arr[i];
        int maxcount=1;
        int summ=0;
        for(auto it:arr)
            summ+=it;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[j]<arr[i]){
                    if(count[j]+1>count[i]){
                        maxcount=max(maxcount,count[j]+1);
                        count[i]=count[j]+1;
                        sum[i]=sum[j]+arr[i];
                    }else if(count[j]+1==count[i]){
                        sum[i]=min(sum[i],sum[j]+arr[i]);
                    }
                }
                
            }
        }
        int ans=summ+1;
        for(int i=0;i<n;i++){
            // cout<<count[i]<<" "<<sum[i]<<endl;
            if(count[i]==maxcount){
                
                ans=min(ans,sum[i]);
            }
        }
        return summ-ans;
    }
};

