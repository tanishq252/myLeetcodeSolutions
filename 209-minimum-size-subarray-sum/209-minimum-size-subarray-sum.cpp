class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0;
        int minSize = INT_MAX;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            while(sum>=target){
                minSize = min(minSize, i-l+1);
                sum-=nums[l++];
            }
        }
        return (minSize == INT_MAX) ? 0:minSize;
    }
};