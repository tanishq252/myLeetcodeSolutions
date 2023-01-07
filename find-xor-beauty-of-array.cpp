// https://leetcode.com/contest/biweekly-contest-95/problems/find-xor-beauty-of-array/

class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        long long int ans = nums[0];
        for(int i=1;i<nums.size();i++){
            ans^=nums[i];
        }
        return ans;
    }
};