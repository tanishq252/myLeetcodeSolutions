class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int mid = nums.size()/2;
        if(target<nums[0]){
            return 0;
        }
        else if(target>nums[nums.size()-1]){
            return nums.size();
        }
        else if(target>nums[mid]){
            int j =mid;
            while(target>nums[j]){
                j++;
            }
            return j;
        }
        else if(target == nums[mid]){
            return mid;
        }
        else if(target<nums[mid]){
            int j = 0;
            while(target>nums[j]){
               j++; 
            }
            return j;
        }
        
        
        return 0;
    }
};