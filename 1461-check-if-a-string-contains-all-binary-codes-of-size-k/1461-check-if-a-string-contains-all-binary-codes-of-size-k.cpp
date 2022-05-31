class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = 2;
        if(k>=s.length()) return false;
        for(int i=1;i<k;i++){
            n<<=1;
        }
        set<string> st;
        cout<<n;
        for(int i=0;i<=s.length()-k;i++){
            string temp(s.begin()+i, s.begin()+i+k);
            st.insert(temp);
        }

        return st.size() == n;
    }
};