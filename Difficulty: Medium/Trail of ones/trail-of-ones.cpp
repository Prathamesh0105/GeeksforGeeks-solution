class Solution {
  public:
    int countConsec(int n) {
        // code here
        int one = 1;
        int zero = 1;
        for(int i = 1; i < n; i++) {
            zero += one;
            one = zero - one;
        }
        
        return pow(2, n) - (zero + one);
    }
};