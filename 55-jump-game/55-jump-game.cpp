class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), lower = 0, upper;
        vector<bool> dp(n, false);
        dp[0] = true;
        for(int i=0;i<n;i++){
            if(!dp[i]) continue;
            upper = min(n-1, i+nums[i]);
            if(upper >= n-1) return true;
            for(int j=i+1;j<=upper;j++){
                dp[j] = true;
            }
        }
        for(auto i:dp) cout<<i<<" ";
        return dp[n-1];
    }
};