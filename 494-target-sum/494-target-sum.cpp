class Solution {
public:
    int trgt;
    int c = 0;
    
    void calc(int ind, int sum, vector<int> &nums){
        if(ind == nums.size()){
            if(sum == trgt){
                c++;
            }
            return;
        }
        calc(ind+1, sum+nums[ind], nums);        
        calc(ind+1, sum-nums[ind], nums);

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        trgt = target;
        calc(0, 0, nums);
        return c;
    }
};