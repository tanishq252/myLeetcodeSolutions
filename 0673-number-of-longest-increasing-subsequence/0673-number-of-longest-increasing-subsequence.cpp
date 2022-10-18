class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        int ans=0;
        vector<int> dp(n, 1), cnt(n, 1);
        vector<int> freq(2000);
        int mx = 1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i] > nums[j]){
                    if(dp[i] == dp[j]+1) cnt[i] += cnt[j];
                    else if(dp[j]+1 > dp[i]) cnt[i] = cnt[j];
                    dp[i] = max(dp[i], dp[j]+1);
                    mx = max(mx, dp[i]);
                }
            }
        }
        for(int i=0;i<nums.size();i++){
            if(dp[i]==mx)ans+=cnt[i];
        }
        return ans;
    }
};