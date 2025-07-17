class Solution {
  public:
    vector<int> GetPrimes(int n){
        vector<bool> seives(n+1, true);
        vector<int> primes;
        
        for(long i = 2;i<=n;i++){
            if(seives[i] == true){
                primes.push_back(i);
                for(long j = i*i; j<=n;j+=i){
                    seives[j] = false;
                }
            }
        }
        
        return primes;
    }
    int maxKPower(int n, int k) {
        vector<int> primes = GetPrimes(k);
        
        map<int,int> kfactors;
        for(int i = 0;i<primes.size();i++){
            while(k%primes[i] == 0){
                kfactors[primes[i]]++;
                k/=primes[i];
            }
        }
        
        int ans = 1e5;
        for(auto i : kfactors)
        {
            long long f = i.first;
            
            int cnt = 0;
            while(f<=n){
                cnt += (n/f);
                f*=i.first;
            }
            
            ans = min(ans, cnt/i.second);
        }
        
        return ans;
    }
}; 