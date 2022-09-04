class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        map<int, int> mp;
        for(auto i:nums){
            mp[i]++;
        }
        int p=0, l=0;
        for(auto i:mp){
            p+= (i.second/2);
            l+= (i.second%2);
        }
        return {p, l};
    }
};