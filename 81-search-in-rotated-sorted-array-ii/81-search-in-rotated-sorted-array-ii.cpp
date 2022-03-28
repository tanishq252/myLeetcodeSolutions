class Solution {
public:
    bool search(vector<int>& nums, int target) {
        return (count(nums.begin(), nums.end(), target)>=1);
    }
};