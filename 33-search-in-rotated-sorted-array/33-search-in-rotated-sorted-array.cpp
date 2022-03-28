class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n==1 && nums[0]!=target){return -1;}
        if(nums[0] == target){return 0;}
        if(nums[n-1] == target){return n-1;}
        if(target<nums[n-1]){
            int i = n-1;
            while(target<nums[i]&&i>=0){
                i--;
                if(target == nums[i]){
                    return i;
                }
                if(i==0){
                    return -1;
                }
            }
        }
        else if(target>nums[0]){
            int i = 0;
            while(target>nums[i]&&i<=n-1){
                i++;
                if(target == nums[i]){
                    return i;
                }
                if(i==n-1){
                    return -1;
                }
            }
        }
        return -1;
    }
};