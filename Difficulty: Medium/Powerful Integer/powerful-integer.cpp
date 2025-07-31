class Solution {
  public:
    int powerfulInteger(vector<vector<int>>& intervals, int k) {
        map<int , int> mp;
        int n = intervals.size();
        for(int i =0; i<n; i++){
            mp[intervals[i][0]]++;
            mp[intervals[i][1]+1]--;
        }
        int count = 0, maxNum = -1;
        for(auto &it: mp){
            count += it.second;
            if(count >=k ){
                if(it.second < 0){
                    maxNum = it.first-1;
                }else{
                    maxNum = it.first;
                }
            }else if(count >= k+it.second && it.second < 0){
                maxNum = it.first-1;
            }
        }
        return maxNum;
    }
};