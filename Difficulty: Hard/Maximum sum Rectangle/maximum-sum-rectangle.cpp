class Solution {
  public:
    int maxRectSum(vector<vector<int>> &mat) {
        // code here
        int ans=INT_MIN;
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int j=0;j<m;j++)
        {
            dp[0][j]=mat[0][j];
        }
        for(int i=1;i<n;i++)
        {   
            for(int j=0;j<m;j++)
           {
            dp[i][j]=dp[i-1][j]+mat[i][j];
           }
        
        }
        for(int i=0;i<n;i++)
        {   
            for(int j=i;j<n;j++)
            {
                int sum=0;
                for(int k=0;k<m;k++)
                {
                    sum+=dp[j][k];
                    if(i>0)
                    {
                        sum-=dp[i-1][k];
                    }
                    ans=max(ans,sum);
                    if(sum<0)
                    {
                        sum=0;
                    }
                    
                    
                }
                
            }
        }
        return ans;
    }
};
