class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
         return maxSumDivK(nums, 3);
    }
    
    int maxSumDivK(vector<int> nums, int k){
        vector<int> dp(k, INT_MIN);
        dp[0] = 0;
        
        for(int i=1;i<=nums.size();i++){
            int n = nums[i-1];
            int mod = nums[i-1]%k;
            
            //create a temporary array
            vector<int> newDP(k, 0);
            
            //iterate through all the columns
            for(int j=0; j<k; j++){
                newDP[j] = max(dp[j], n+dp[(j+mod)%k]);
            }
            dp = newDP;
        }
        
        return dp[0];
    }
};