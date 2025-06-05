class Solution {
  public:
    int countPaths(vector<vector<int>>& E, int V, int S, int D) {
        vector<vector<int>> G(V); vector<int> I(V);
        for (auto& e : E) G[e[0]].push_back(e[1]), I[e[1]]++;
        queue<int> Q; for (int i = 0; i < V; i++) if (!I[i]) Q.push(i);
        vector<int> T, dp(V); dp[D] = 1;
        while (!Q.empty()) {
            int u = Q.front(); Q.pop(); T.push_back(u);
            for (int v : G[u]) if (--I[v] == 0) Q.push(v);
        }
        for (int i = V - 1; i >= 0; i--)
            for (int v : G[T[i]]) dp[T[i]] += dp[v];
        return dp[S];
    }
};