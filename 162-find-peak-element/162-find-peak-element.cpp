class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        for(int i=0;i<nums.size();i++){
            if(i>0 and i<nums.size()-1){
                if(nums[i] > nums[i-1] and nums[i] > nums[i+1]){
                    return i;
                }
            }
            if(i == 0){
                if(nums[0] > nums[1]){
                    return 0;
                }
            }
            if(i == nums.size() - 1){
                if(nums[nums.size()-1] > nums[nums.size()-2]){
                    return i;
                }
            }
        }
        return 0;
    }
};