class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, vector<int>> mp;
        for(int i=0;i<nums.size();i++){
            if(mp[nums[i]].size() >= 1){
                for(int j=0;j<mp[nums[i]].size();j++){
                    if(abs(i-mp[nums[i]][j])<=k){
                        return true;
                    }
                }
            }
            mp[nums[i]].push_back(i);
        }
        return false;
    }
};