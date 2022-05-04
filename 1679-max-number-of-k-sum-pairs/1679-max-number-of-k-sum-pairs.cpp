class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i=0, j = nums.size()-1;
        int ans=0;
        while(i<j){
            int s = nums[i]+nums[j];
            if(s>k){
                j--;
            }else if(s<k){
                i++;
            }else if(s == k){
                ans++;
                i++;
                j--;
            }
        }
        return ans;
    }
};