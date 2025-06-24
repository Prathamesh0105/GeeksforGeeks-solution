#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    string maxSubseq(string& s, int k) {
        deque<int> q;
        int q_idx = 0;
        int idx = 0;
        string res;
        while (k > 0 && idx < s.size() - k) {
            int nq_idx = min(idx + k + 1, (int) s.size());
            for (int i = q_idx; i < nq_idx; i++) {
                while (q.size() > 0 && s[q.back()] < s[i]) q.pop_back();
                q.push_back(i);
            }
            q_idx = nq_idx;

            while(q.size() > 0 && q.front() < idx) q.pop_front();

            res.push_back(s[q.front()]);
            
            k -= q.front() - idx;
            
            idx = q.front() + 1;

        }
        
        if (idx < s.size() - k)
            res.append(s.substr(idx, s.size()-idx));

        return res;
    }
};