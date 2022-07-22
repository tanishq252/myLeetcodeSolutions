class Solution {
public:
    int findMaxGreater(int x, vector<int> &nums){
        for(int i=x;i<nums.size();i++){
            if(nums[i] > nums[x]){
                return nums[i];
            }
        }
        for(int i=0;i<x;i++){
            if(nums[i] > nums[x]){
                return nums[i];
            }
        }
        return -1;
    }
    
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            ans.push_back(findMaxGreater(i, nums));
        }
        return ans;
    }
};