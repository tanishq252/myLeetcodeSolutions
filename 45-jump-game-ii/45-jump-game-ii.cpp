class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        for(int i=0;i<n;i++){
            int k = min(i+nums[i], n-1);
            for(int j = i+1;j<=k;j++){
                if(dp[j] == 0){
                    dp[j] = dp[i]+1;
                    if(j == n-1) break;
                }
            }
        }
        // cout<<dp[n-1];
        return dp[n-1];
    }
};