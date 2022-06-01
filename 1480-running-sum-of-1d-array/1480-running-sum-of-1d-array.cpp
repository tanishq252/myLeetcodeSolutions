class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            ans.push_back(accumulate(nums.begin(), nums.begin()+i+1, 0));
        }
        // for(int i=1;i<nums.size();i++){
        //     nums[i] += nums[i-1];
        // }
        return ans;
    }
};