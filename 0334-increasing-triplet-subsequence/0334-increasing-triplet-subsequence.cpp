class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        int sm=INT_MAX, bg = INT_MAX;
        for(auto &i:nums){
            if(i<=sm) sm=i;
            else if(i<=bg) bg=i;
            else return true;
        }
        return false;
        // dp[n-1]=1;
        // for(int i=n-1;i>=0;i--){
        //     for(int j=i+1;j<n;j++){
        //         if(nums[i] < nums[j]){
        //             dp[i] = max(dp[i], dp[j]+1);
        //         }
        //         if(dp[i] == 3) return true;
        //     }
        // }
        // for(auto &i:dp) cout<<i<<" ";
        // return (dp[0]==3)?true:false;
    }
};