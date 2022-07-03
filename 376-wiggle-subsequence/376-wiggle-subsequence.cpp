class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        if(nums.size() == 1) return 1;
        int k =1 ;
        while(nums[k] == nums[k-1] and k<nums.size()-1){
            k++;
        }
        int flag = (nums[k-1]>nums[k]) ? 0:1;
        for(int i=k;i<nums.size();i++){
            if(flag == 1 and nums[i]-nums[i-1] > 0){
                flag = 0;
                dp[i] = dp[i-1]+1;
            }else if(flag == 0 and nums[i] - nums[i-1]<0){
                flag = 1;
                dp[i] = dp[i-1]+1;
            }else{
                dp[i] = dp[i-1];
            }
        }
        return dp[dp.size()-1];
    }
};