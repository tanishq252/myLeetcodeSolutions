class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n, -1);
        int den = 2*k+1;
        if(den > n) return ans;
        long long int sum = 0;
        for(int i=0;i<=2*k;i++){
            sum+=nums[i];
        }
        ans[k] = sum/den;
        for(int i = k;i<n-k-1;i++){
            sum-=nums[i-k];
            sum+=(nums[i+k+1]);
            ans[i+1] = sum/den;
        }
        return ans;
    }
};