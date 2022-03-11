class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        int sum = accumulate(nums.begin(), nums.end(),0);
        int s=0,j;
        for(int i=0;i<nums.size();i++){
            s+=nums[i];
            if(2*s>sum){
                j = i;
                break;
            }
        }
        vector<int> v;
        for(int i=0;i<=j;i++){
            v.push_back(nums[i]);
        }
        return v;
    }
};