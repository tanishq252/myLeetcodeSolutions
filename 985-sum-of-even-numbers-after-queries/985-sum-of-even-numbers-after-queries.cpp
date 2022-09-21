class Solution {
public:

    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans(nums.size());
        int s=0, j=0;
        for(auto &i:nums){
            if(i%2==0) s+=i;
        }
        for(auto &i:queries){
            if(nums[i[1]]%2 == 0) s -= nums[i[1]];
            nums[i[1]] += i[0];
            if(nums[i[1]]%2 == 0) s += nums[i[1]];
            ans[j++] = s;
            
        }
        return ans;
    }
};