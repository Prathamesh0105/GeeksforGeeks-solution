class Solution {
  public:
    bool divby13(string &s) {
        int i=0,Q=0;
        int n=s.size();
    
        
        while(i<n)
        {
            Q=(Q*10+(s[i]-'0'));
            Q=Q%13;
            i++;
        }
        if(Q==0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};