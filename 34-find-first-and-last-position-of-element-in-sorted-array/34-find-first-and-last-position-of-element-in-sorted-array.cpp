class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0) return {-1, -1};
        vector<int> ans =  {-1, -1};
        int i=0,j = nums.size()-1;
        while(nums[i]<target ){
            i++;
            if(i==nums.size()){return {-1,-1};}
        }
        while(nums[j]>target and j>=0){
            j--;
            if(j<0){break;}
        }
        if(j<0 or i>nums.size()-1) return {-1, -1};
        if(nums[i]!=target and nums[j]!=target){return {-1, -1};}
        return {i, j};
    }
};