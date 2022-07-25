class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int i=0, j = nums.size()-1;
        vector<int> ans;
        while(i <= j){
            if(nums[i]<target){
                i++;
            }
            else if(nums[i] == target){
                ans.push_back(i);
                i++;
            }
            if(nums[j]>target){
                j--;
            }
            else if(nums[j] == target){
                ans.push_back(j);
                j--;
            }
        }
        sort(ans.begin(), ans.end());
        if(ans.size() == 1){
            return {ans[0], ans[0]};
        }else if(ans.size()>1){
            return {ans[0], ans[ans.size()-1]};
        }
        return {-1, -1};
    }
};