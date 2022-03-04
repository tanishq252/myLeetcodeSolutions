class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int j = nums.size()-1;j>=2;j--){
            if(nums[j]<nums[j-1]+nums[j-2]){
                return nums[j]+nums[j-1]+nums[j-2];
            }
        }
        return 0;
    }
};