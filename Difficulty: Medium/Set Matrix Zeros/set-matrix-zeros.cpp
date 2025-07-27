class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        vector<pair<int,int>> v;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0)  v.emplace_back(i,j);
            }
        }
        
        for(auto ele:v){
            int r = ele.first;
            int c = ele.second;
            
            //cout<<"r:"<<r<<" "<<"c:"<<c<<'\n';
            
            for(int i = 0; i < m; i++) mat[r][i] = 0;
            for(int i = 0; i < n; i++) mat[i][c] = 0;
        }
    }
};