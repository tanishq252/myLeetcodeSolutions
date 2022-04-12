class Solution {
public:
    
    string toLowerCase(string s) {
        string s1="";
        for(auto i:s){
            s1+=(i-'a'<0 && i>='A'&&i<='Z')?char(i+32):i;
        }
        return s1;
    }
};