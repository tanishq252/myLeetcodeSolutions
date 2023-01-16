class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        long long ans=0, pairs=0;
        int j=0;
        for(int i=0;i<nums.size();i++){
            while(j<nums.size() and pairs < k){
                pairs += mp[nums[j]];
                mp[nums[j]]++;
                j++;
            }
            if(pairs >= k){
                ans += nums.size()-j+1;
            }
            mp[nums[i]]--;
            pairs -= mp[nums[i]];
        }
        return ans;
    }
};