class Solution {
  public:
    int balanceSums(vector<vector<int>>& mat) {
         int n = mat.size();
         int a = INT_MIN;
         int b = INT_MIN;
         int final = 0;
        //  max sum of any row
         for(int i=0; i< n ; i++){
             int temp = 0;
             for(int j = 0 ; j < n ; j++){
                temp +=  mat[i][j];
             }
             a = max(a,temp);
             
         }
        //  max sum of any column
            for(int j=0; j< n ; j++){
             int temp = 0;
             for(int i = 0 ; i < n ; i++){
                temp +=  mat[i][j];
             }
             
             b = max(b,temp);
             
         }
        //  max sum of any row or column in matrix
        int ans = max(a,b);
        
        for(int i=0; i< n ; i++){
             int temp = 0;
             for(int j = 0 ; j < n ; j++){
                temp +=  mat[i][j];
             }
            //  number of opration requied
               final += (ans-temp);
             
         }
        return final;
    }
};