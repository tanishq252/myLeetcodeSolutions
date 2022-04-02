class Solution {
public:
    bool ispal(string s){
        int i=0, j=s.length()-1;
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;j--;
        }
        return true;
    }
    
    bool isPalindrome(string s) {
        string st;
        for(int i=0;i<s.length();i++){
            if(tolower(s[i])>=97 && tolower(s[i])<=122){
                st.push_back(tolower(s[i]));
            }
            else if(tolower(s[i])>=48 && tolower(s[i])<=57){
                st.push_back(tolower(s[i]));
            }
        }
        return ispal(st);
    }
};