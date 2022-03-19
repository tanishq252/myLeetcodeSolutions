class Solution {
public:
    bool areOccurrencesEqual(string s) {
        map<char, int> m;
        for(int i=0;i<s.length();i++){
            m[s[i]]++;
        }
        set<int> st;
        for(int i=0;i<s.length();i++){
            st.insert(m[s[i]]);
        }
        return st.size()==1;
    }
};