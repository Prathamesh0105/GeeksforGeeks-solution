class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        // Code here
        sort(prices.begin(),prices.end());
        // minimum price
        int i=0,j=prices.size()-1;
        int mini=0;
        while(i<=j){
            mini+=prices[i];
            i++;
            j=j-k;
        }
         // maximum price
         i=0,j=prices.size()-1;
        int maxi=0;
        while(i<=j){
            maxi+=prices[j];
            i=i+k;
            j--;
        }
        return {mini,maxi};
    }
};