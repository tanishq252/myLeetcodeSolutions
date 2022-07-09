class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        vector<int> scores(nums.size(), 0);
        for(int i = nums.size() - 1;i>=0;i--){
            while(pq.size() and pq.top().second > i+k){
                pq.pop();
            }
            scores[i] = nums[i];
            scores[i] += pq.size() ? pq.top().first:0;
            pq.push({scores[i], i});
        }
        return scores[0];
    }
};