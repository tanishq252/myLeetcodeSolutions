class Solution {
public:
    string change(string s, int ind){
        if(islower(s[ind])){
            s[ind] = toupper(s[ind]);
        }else{
            s[ind] = tolower(s[ind]);
        }
        return s;
    }
    
    void combos(set<string> &ans, string s, int ind){
        while(ind<s.length() and s[ind] - 'A' < 0){ind++;}
        ans.insert(s);

        if(ind >= s.length()) return;
        
        s = change(s, ind);
        combos(ans, s, ind+1);
        s = change(s, ind);
        combos(ans, s, ind+1);
        
    }
    
    vector<string> letterCasePermutation(string s) {
        set<string> ans;
        combos(ans, s, 0);
        return vector<string> (ans.begin(), ans.end());
    }
};