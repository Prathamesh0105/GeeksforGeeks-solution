class Solution {
  public:
    vector<int> asciirange(string& s) {
        int n = s.length() ; 
        vector<pair<int,int>> mp(26,{-1 ,-1}) ; 
        vector<int>pref ; 
        pref.push_back(0); 
        for(int i = 0 ; i < n ; i++){
            char ch = s[i] ; 
            pref.push_back(pref.back()+static_cast<int>(ch)) ; 
            if(mp[ch-'a'].first == -1){
                mp[ch-'a'].first = i ; 
            }
            mp[ch-'a'].second = i ; 
        }
        vector<int>res ;
        for(int i =0 ; i < n ; i++){
            int first_occ = mp[s[i] - 'a'].first ; 
            int last_occ = mp[s[i] - 'a'].second ;
            if(first_occ == last_occ) continue ; 
            int sum = pref[last_occ] - pref[first_occ+1] ; 
            if(sum == 0) continue ;
            res.push_back(sum) ; 
            mp[s[i]-'a'].first = -1 ; 
            mp[s[i] -'a'].second = -1 ; 
        }
        return res ; 
    }
};