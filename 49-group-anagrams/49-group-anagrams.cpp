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
        vector<vector<string>> ansVec;
        for(auto i: mp){
            ansVec.push_back(i.second);
        }
        // vector<vector<string>> ansVec(ansSet.begin(), ansSet.end());
        return ansVec;
    }
};