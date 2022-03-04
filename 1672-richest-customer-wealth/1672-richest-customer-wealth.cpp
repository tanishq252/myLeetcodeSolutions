class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        vector<int> v;
        for(int i=0;i<accounts.size();i++){
            v.push_back(accumulate(accounts[i].begin(), accounts[i].end(), 0));
        }
        return *max_element(v.begin(), v.end());
    }
};