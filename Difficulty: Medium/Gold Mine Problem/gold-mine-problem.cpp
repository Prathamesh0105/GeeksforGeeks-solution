class Solution {
  public:
    int maxGold(vector<vector<int>>& mat) {
        // code here
         int n=mat.size();
        int m=mat[0].size();
        vector<int>prev(n);
        for(int i=0;i<n;i++){
            prev[i]=mat[i][0];
        }
        vector<int>curr(n,0);
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                if(j==0){
                    curr[j]=mat[j][i]+max(prev[j],prev[j+1]);
                }
                else if(j==n-1){
                    curr[j]=mat[j][i]+max(prev[j],prev[j-1]);
                }
                else{
                    curr[j]=mat[j][i]+max({prev[j+1],prev[j],prev[j-1]});
                }
            }
            prev=curr;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,prev[i]);
        }
        return ans;
    }
};