class Solution {
  public:
    int minCost(vector<int>& heights, vector<int>& cost) {
        int n = heights.size();
        vector<pair<int, int>> towers(n);
        
        for (int i = 0; i < n; ++i) {
            towers[i] = {heights[i], cost[i]};
        }
        
        sort(towers.begin(), towers.end());
        
        long long totalCost = 0;
        for (int i = 0; i < n; ++i) {
            totalCost += towers[i].second;
        }
        
        long long curr = 0;
        int targetHeight = 0;
        for (int i = 0; i < n; ++i) {
            curr += towers[i].second;
            if (curr >= (totalCost + 1) / 2) {  
                targetHeight = towers[i].first;
                break;
            }
        }
        
        // Calculate total cost
        long long result = 0;
        for (int i = 0; i < n; ++i) {
            result += 1LL * abs(heights[i] - targetHeight) * cost[i];
        }
        
        return result;
    }
};
