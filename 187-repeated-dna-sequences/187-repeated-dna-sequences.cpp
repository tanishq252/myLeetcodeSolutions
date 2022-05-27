class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.length() <= 10)return {};
        unordered_map<string, int> mp;
        set<string> st;
        for(int i=0;i<=s.length()-10;i++){
            string temp(s.begin()+i,s.begin()+i+10);
            mp[temp]++;
            if(mp[temp]>1) st.insert(temp);
        }
        vector<string> ans(st.begin(), st.end());
        return ans;
    }
};