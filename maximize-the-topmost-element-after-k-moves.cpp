// https://leetcode.com/problems/maximize-the-topmost-element-after-k-moves/submissions/873147199/
// greedy, we have to look for k-1 elements rather than the kth

class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n = nums.size(),mx;
        if(n==1 and k%2==1) return -1;
        if(k<=1) return nums[k];
        if(k >= n){
            if(k==n){
                return *max_element(nums.begin(), nums.end()-1);
            }
            mx = *max_element(nums.begin(), nums.end());
        }
        else{
            mx = *max_element(nums.begin(), nums.begin()+k-1);
            mx = max(mx, nums[k]);
        }
        return mx;
    }
};