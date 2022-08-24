class Solution {
public:
    // 29/39 test cases
    const int mod = 1000000007;
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n, -1);
        int den = 2*k+1;
        if(den > n) return ans;
        // cout<<(unsigned long long) accumulate(nums.begin(), nums.begin()+2*k+1, 0)%mod;
        long long int sum = 0;
        for(int i=0;i<=2*k;i++){
            sum+=nums[i];
        }
        cout<<sum/den;
        // sum%=mod;
        ans[k] = sum/den;
        for(int i = k;i<n-k-1;i++){
            sum-=nums[i-k];
            sum+=(nums[i+k+1]);
                        // sum%=mod;
            ans[i+1] = sum/den;
            // cout<<sum/den<<" ";
        }
        return ans;
    }
};