class Solution {
  public:
    int getCount(int n) {
        // code here
        vector<vector<int>> dp(n+1, vector<int>(10, 0));
        
        vector<vector<int>> adj(10);
        
        adj[0] = {0, 8};
        adj[1] = {1, 2, 4};
        adj[2] = {1, 2, 3, 5};
        adj[3] = {2, 3, 6};
        adj[4] = {1, 4, 5, 7};
        adj[5] = {2, 4, 5, 6, 8};
        adj[6] = {3, 5, 6, 9};
        adj[7] = {4, 7, 8};
        adj[8] = {0, 5, 7, 8, 9};
        adj[9] = {6, 8, 9};
        
        for(int digit=0; digit<10; digit++) dp[1][digit] = 1;
        
        for(int len=2; len<=n; len++) {
            for(int digit=0; digit<10; digit++) {
                for(int adj_digit: adj[digit]) {
                    dp[len][digit] += dp[len-1][adj_digit];
                }
            }
        }
        
        int ans = 0;
        
        for(int digit=0; digit<10; digit++) {
            ans += dp[n][digit];
        }
        
        return ans;
    }
};