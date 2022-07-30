class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx = INT_MIN;
        int pref=1, suff=1;
        int n = nums.size();
        for(int i=0;i<n;i++){
            pref = (pref?pref:1)*nums[i];
            suff = (suff?suff:1)*nums[n-i-1];
            mx = max(mx, max(pref, suff));
        }
        return mx;
        
        // int mx = INT_MIN;
        // int n = nums.size();
        // int sum=1;
        // for(int i=0;i<n;i++){
        //     sum=1;
        //     for(int j=i;j<n;j++){
        //         sum*=nums[j];
        //         mx = max(sum, mx);
        //     }
        // }
        // cout<<n;
        // return mx;
    }
};