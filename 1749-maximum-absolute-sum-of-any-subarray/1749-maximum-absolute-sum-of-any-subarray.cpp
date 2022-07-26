class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int mx = 0;
        int mn = 0;
        int s = 0;
        for(auto &i: nums){
            s += i;
            mn = min(mn, s);            
            mx = max(mx, s);
        }
        return mx - mn;
    }
};