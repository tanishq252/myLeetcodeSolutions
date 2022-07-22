class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        if(nums.size() == 2 and nums[0]!=nums[1]){return nums;}
        set<int> s(nums.begin(), nums.end());
        vector<int> ans;
        for(auto i:s){
            if(count(nums.begin(), nums.end(), i) == 1){
                ans.push_back(i);
                if(ans.size() == 2) return ans;
            }
        }
        return ans;
    }
};