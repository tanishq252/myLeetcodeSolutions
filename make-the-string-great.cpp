// https://leetcode.com/problems/make-the-string-great/description/

class Solution {
public:
    string makeGood(string s) {
        int i=0;
        while(i<s.length()){
            if(i<s.length()-1){
                if(s[i]-'a' == s[i+1]-'a'+32 or s[i+1]-'a' == s[i]-'a'+32){
                    s.erase(i, 2);
                    if(s=="") return "";
                    if(i>0){
                        i-=2;
                    }
                    if(i==0){
                        i--;
                    }
                }
            }
            i++;
        }
        return s;
    }
};