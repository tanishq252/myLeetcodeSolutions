class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int pos = lower_bound(nums.begin(), nums.end(), target)-nums.begin();
        // cout<<pos;
        return pos;
    }
};