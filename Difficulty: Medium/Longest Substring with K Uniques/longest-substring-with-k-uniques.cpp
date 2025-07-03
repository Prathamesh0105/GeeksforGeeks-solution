class Solution {
  public:
     int longestKSubstr(string &s, int k) {
        // code here
        int n=s.size();
        vector<int>freq(26,0);
        int count=0;
        int len=0;
        int i=0,j=0,maxi=-1;
        while(j<n){
            freq[s[j]-'a']++;
            len++;
            if(freq[s[j]-'a']==1){
                count++;
            }
            while(count>k){
                freq[s[i]-'a']--;
                if(freq[s[i]-'a']==0){
                    count--;
                }
                i++;
            }
            if(count==k){
                maxi=max(maxi,j-i+1);
            }
            j++;
            
        }
        return maxi;
    }
};