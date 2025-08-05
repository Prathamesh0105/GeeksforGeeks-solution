class Solution {
  public:
  bool isPalinSent(string &s) {
        int n=s.length();
        string pali="";
        for(int i=0;i<n;i++){
          if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0'&& s[i]<='9')|| (s[i]>='0' && s[i]<='9')){
              pali+=tolower(s[i]);
          }else{
              continue;
          }
        }
        for(int i=0;i<pali.length()/2;i++){
            if(pali[i]!=pali[pali.length()-i-1]){
                return false;
            }
        }
        return true;
    }
};