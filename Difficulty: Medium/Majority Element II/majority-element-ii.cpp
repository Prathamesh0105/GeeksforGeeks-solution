class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
        unordered_map<int,int>hash;
        for(auto i:arr)hash[i]++;
        int n=arr.size();
        vector<int>ans;
        int k=(n)/3;
        for(auto i:hash){
            if(i.second>k)ans.push_back(i.first);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};