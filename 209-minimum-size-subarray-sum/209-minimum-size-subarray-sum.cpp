class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if(accumulate(nums.begin(), nums.end(), 0) < target) return 0;
        if(accumulate(nums.begin(), nums.end(), 0) == target) return nums.size();
        if(count(nums.begin(), nums.end(), target)>0) return 1;
        int sum =0;
        int l=0, ms =INT_MAX;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            while(sum>=target){
                ms = min(ms, i-l+1);
                sum-=nums[l++];
            }
        }
        return ms;
        
    }
};