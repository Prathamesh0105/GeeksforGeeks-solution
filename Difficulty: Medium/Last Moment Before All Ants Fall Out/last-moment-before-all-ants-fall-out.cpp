class Solution {
  public:
    int fromLeft(vector<int>& left){
        int ans = -1;
        for(auto z: left){
            ans= max(ans, z);
        }
        return ans;
    }
    int fromRight(vector<int>& right, int& n){
        int ans = INT_MAX;
        for(auto z: right){
            ans = min(ans, z);
        }
        return n-ans;
    }
  
  
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        // code here
        int ans1 = fromLeft(left);
        int ans2 = fromRight(right, n);
        
        return max(ans1, ans2);
    }
};

