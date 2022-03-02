class Solution {
public:
    string truncateSentence(string s, int k) {
        string s1="";
        int i=0;
        for(int i=0;i<s.length();i++){
            
            if(s[i] == ' ') k--;
            if(k == 0){break;}
            s1 += s[i];
        }
        
        return s1;
    }
};