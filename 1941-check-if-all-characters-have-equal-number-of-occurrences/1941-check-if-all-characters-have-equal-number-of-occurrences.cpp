class Solution {
public:
    bool areOccurrencesEqual(string s) {
        map<char, int> m;
        set<char> st1;
        for(int i=0;i<s.length();i++){
            m[s[i]]++;st1.insert(s[i]);
        }
        set<int> st;
        for(auto i=st1.begin();i!=st1.end();i++){
            st.insert(m[*i]);
        }
        return st.size()==1;
    }
};