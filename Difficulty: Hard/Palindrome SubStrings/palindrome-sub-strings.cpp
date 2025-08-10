class Solution {
  public:
    int countPS(string &s) {
        int n = s.length();
        int count = 0;
        
        for (int center = 0; center < n; center++) {
            
            int left = center, right = center;
            while (left >= 0 && right < n && s[left] == s[right]) {
                if (right - left + 1 >= 2) {
                    count++;
                }
                left--;
                right++;
            }
            
            left = center;
            right = center + 1;
            while (left >= 0 && right < n && s[left] == s[right]) {
                count++;
                left--;
                right++;
            }
        }
        
        return count;
    }
};