// https://leetcode.com/problems/maximal-score-after-applying-k-operations/submissions/

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans=0L,x;
        priority_queue<long long> pq;
        for(auto &i:nums) pq.push(i);
        while(k--){
            x = pq.top();
            pq.pop();
            ans+=x;
            pq.push(ceil((double)x/3));
        }
        return ans;
    }
};