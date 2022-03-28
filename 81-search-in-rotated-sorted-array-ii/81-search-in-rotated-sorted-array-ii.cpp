class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n==1 && nums[0]!=target){return false;}
        if(nums[0] == target||nums[nums.size()-1] == target){return true;}
        int low = 0;
        int high = n-1;
        while (low< high && nums[low] == nums[low + 1])
            ++low;
        while (low< high && nums[high] == nums[high - 1])
            --high;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid] == target){return true;}
            
            if(nums[mid]>=nums[low]){
                if(target<nums[mid]&&target>=nums[low]){
                    high =mid-1;
                }else{
                    low = mid+1;
                }
            }
            else{
                if(target>nums[mid]&&target<=nums[high]){
                    low = mid+1;
                }else{
                    high = mid-1;
                }
            }
        }
        return false;
    }
};