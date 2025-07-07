class Solution {
  public:
     vector<int> nextLargerElement(vector<int> &arr) {
      
      int n=arr.size();
      vector<int>ans(2*n);
      
       for(int i=0; i<n; i++){
          ans[i]=arr[i];
          ans[n+i]=arr[i];
      }
      
     
       stack<int>st;
     
       vector<int>result(2*n);
      
       result[result.size()-1]=-1;
      
       st.push(ans[ans.size()-1]);
       
      for(int i=ans.size()-2; i>=0; i--){
         
          
          while(st.size() > 0 && st.top() <= ans[i]){
              st.pop();
          }
          
         if(st.size() > 0) result[i]=st.top();
         else result[i]=-1;
         
          st.push(ans[i]);
          
          
      }
     vector<int>fi(n);
     
      for(int i=0; i<n; i++){
          
          fi[i]=result[i];
          
      }
      return fi;
        
    }
};