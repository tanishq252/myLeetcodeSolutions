class Solution {
public:
    int find(vector<int>& nums, int original){
        for(int i=0;i<nums.size();i++){
            if(original == nums[i]){
                return find(nums,original*2);
            }
        }
        return original;
    }
    int findFinalValue(vector<int>& nums, int original) {
        return find(nums,original);
    }
};