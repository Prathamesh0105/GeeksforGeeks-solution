class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals,
                                       vector<int> &newInterval) {
        // code here
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        for (auto& it : intervals){
            if (ans.empty()) ans.push_back(it);
            else if (it[0] <= ans.back()[1]) ans.back()[1] = max(ans.back()[1], it[1]);
            else ans.push_back(it);
        }
        return ans;
    }
};