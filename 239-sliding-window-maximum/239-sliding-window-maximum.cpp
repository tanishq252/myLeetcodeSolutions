class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        if(n == k) return {*max_element(nums.begin(), nums.end())};
        if(k == 1) return nums;

    priority_queue<pair<int, int>> pq;
    for (int i = 0;i < n; i++) {
        while(!pq.empty() and pq.top().second <= i-k ) pq.pop();
        pq.push({nums[i], i});
        if(i>=k-1){
            ans.push_back(pq.top().first);
        }
    }
    return ans;
    }
        
        // brute force
//         vector<int> ans;
//         int n = nums.size();
//         if(n == k) return {*max_element(nums.begin(), nums.end())};
//         if(k == 1) return nums;
//         priority_queue<int> pq;
//         for(int i=0;i<=n-k;i++){
//             pq.push(nums[i]);
//             ans.push_back(*max_element(nums.begin()+i, nums.begin()+i+k));
//         }
        
//         return ans;
//     }
};