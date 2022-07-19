class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        string ans;
        map<string, vector<string>> mp;
        for(auto i: strs){
            ans = i;
            sort(ans.begin(), ans.end());
            mp[ans].push_back(i);
        }
        vector<vector<string>> ansVec;
        for(auto i: mp){
            ansVec.push_back(i.second);
        }
        return ansVec;
    }
};