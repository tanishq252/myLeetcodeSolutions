class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int mid = nums.size()/2;
        sort(nums.begin(), nums.end());
        int ans=0;
        for(auto i: nums){
            ans+= abs(nums[mid] - i);
        }
        return ans;
    }
};