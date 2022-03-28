class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n==1 && nums[0]!=target){return false;}
        if(nums[0] == target||nums[nums.size()-1] == target){return true;}
        if(target<nums[n-1]){
            int i = n-1;
            while(target<nums[i]&&i>=0){
                i--;
                if(target == nums[i]){
                    return true;
                }
                if(i==0){
                    return false;
                }
            }
        }
        else if(target>nums[0]){
            int i = 0;
            while(target>nums[i]&&i<=n-1){
                i++;
                if(target == nums[i]){
                    return true;
                }
                if(i==n-1){
                    return false;
                }
            }
        }
        return false;
    }
};