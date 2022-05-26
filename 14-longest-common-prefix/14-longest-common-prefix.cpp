class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        int i=0, j=0;
        if(strs[i] == "") return "";
        set<string> st(strs.begin(), strs.end());
        if(st.size() == 1) return strs[0];
        while(strs[i][j] == strs[i+1][j]){
            i++;
            if(strs[i] == "") return "";
            if(i==strs.size()-1){
                ans+= strs[i][j];
                i = 0;j++;
            }
        }
        return ans;
    }
};