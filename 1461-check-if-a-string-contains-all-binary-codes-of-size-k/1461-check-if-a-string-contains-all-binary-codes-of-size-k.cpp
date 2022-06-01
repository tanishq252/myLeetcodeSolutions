class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.size() <= k) return false;
        set<string> st;
        int n = 1<<k;
        for(int i=0;i<=s.length()-k;i++){
            string t(s.begin()+i, s.begin()+i+k);
            st.insert(t);
        }
        return st.size() == n;
    }
};