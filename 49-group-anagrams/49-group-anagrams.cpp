class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        string ans;
        map<string, vector<string>> mp;
        set<vector<string>> ansSet;
        for(auto i: strs){
            ans = i;
            sort(ans.begin(), ans.end());
            mp[ans].push_back(i);
        }
        for(auto i: strs){
            ans = i;
            sort(ans.begin(), ans.end());
            ansSet.insert(mp[ans]);
        }
        vector<vector<string>> ansVec(ansSet.begin(), ansSet.end());
        // cout<<ans;
        return ansVec;
    }
};