class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
    vector<int> result;
    if (k == 0) return result;
    priority_queue<pair<int, int>> w;
    for (int i = 0, n = (int)nums.size(); i < n; i++) {
        while (!w.empty() && w.top().second <= i-k)
            w.pop();
        w.push(make_pair(nums[i],i));
        if (i >= k-1)
            result.push_back(w.top().first);
    }
    return result;
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