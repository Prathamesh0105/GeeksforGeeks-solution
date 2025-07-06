class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        int n=a.size();
        int m=b.size();
        priority_queue<int,vector<int>,greater<int>>pq;
        sort(a.rbegin(),a.rend());
        sort(b.rbegin(),b.rend());
        for(int i=0;i<n;i++)
        {
            int sum=0;
            for(int j=0;j<m;j++)
            {
                sum=b[j]+a[i];
                if(pq.size()<k)
                    pq.push(sum);
            
                else if(sum>pq.top())
                {
                    pq.pop();
                    pq.push(sum);
                }
                else break;
            }
        }
        vector<int>v;
        while(!pq.empty())
        {
            v.push_back(pq.top());
            pq.pop();
        }
        sort(v.rbegin(),v.rend());
        return  v;
        
    }
};