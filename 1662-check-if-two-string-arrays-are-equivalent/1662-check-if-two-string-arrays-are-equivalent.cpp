class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s="", ss="";
        for(auto &i:word1) s+=i;
        for(auto &i:word2) ss+=i;
        return s==ss;
    }
};