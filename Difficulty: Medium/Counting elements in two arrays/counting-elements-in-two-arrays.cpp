class Solution {
  public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        // code here
        sort(b.begin(),b.end());
        vector<int>ans;
        for(auto x:a){
            auto ub=upper_bound(b.begin(),b.end(),x);
            ans.push_back(ub-b.begin());
        }
        
        return ans;
    }
};