class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        int n = arr.size(), cnt = 0;
        int pc = 0, tc = 0, pd = 0, td = 0;
        for(int i = 0; i < n; i++){
            if(arr[i] == 'P') pc++;
            else tc++;
            int mini = min(pc,tc);
            cnt += mini;
            pc-=mini;
            tc-=mini;
            pd+=mini;
            td+=mini;
            if(i >= k){
                if(arr[i-k] == 'P'){
                    if(pd > 0) pd--;
                    else pc--;
                }
                else{
                    if(td > 0) td--;
                    else tc--;
                }
            }
        }
        return cnt;
    }
};

