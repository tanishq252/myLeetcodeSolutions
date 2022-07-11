class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
         vector<vector<long long>> dp(nums.size()+1, vector<long long>(3, INT_MIN));
        long long a, b;
        dp[0][0] = 0;
        for(int i=1;i<=nums.size();i++){
            for(int j=0;j<=2;j++){
                a = nums[i-1] + dp[i-1][(j+nums[i-1])%3];
                b = dp[i-1][j];
                dp[i][j] = max(a, b);
            }
        }
        return dp[nums.size()][0];
    }
};