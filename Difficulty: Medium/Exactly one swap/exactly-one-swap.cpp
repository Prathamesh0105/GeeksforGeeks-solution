class Solution{
public:
    int countStrings(string &s){
        vector<int> m(26);
        int ans = 0;
        for(int i = 0; i < s.size(); ++i){
            ans += i - m[s[i] - 'a'];
            ++m[s[i] - 'a'];
        }
        for(int x : m) if(x > 1){ ++ans; break; }
        return ans;
    }
};