class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        int mod = 1000000007;
        if(nums.size() == 0) return 0;
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());
        for(int i=0;i<k;i++){
            int m = pq.top(); pq.pop();
            m += 1;
            pq.push(m);
        }
        long long prod = 1;
        while(!pq.empty()){
            prod = ((pq.top()%mod)*(prod%mod))%mod;
            pq.pop();
        }
        return prod;
    }
};