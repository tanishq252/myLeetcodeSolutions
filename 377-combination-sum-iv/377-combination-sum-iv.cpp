class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<uint> dp(target+1, 0);
        sort(nums.begin(), nums.end());
        dp[0] = 1;
        for(int i=1;i<dp.size();i++){
            for(int j=0;j<nums.size();j++)
                if(nums[j]<=i){
                    dp[i]+=dp[i-nums[j]];
                }
        }
        return dp[target];
    }
};